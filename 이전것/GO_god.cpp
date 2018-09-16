//
//  GO_god.cpp
//  baek
//
//  Created by Sean on 2017. 11. 14..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

enum operation { Open, End, alternative, wildcards, kleene, positive, alphabet, error };

typedef struct state {
    int label;
    char edge;
    bool visit;
    struct state* left;
    struct state* right;
    state() : label(0), edge('e'), visit(false), left(NULL), right(NULL) {}
}state;
typedef struct state* ptrS;


class nfa {
private:
    string w;
    string wPostfix;
    ptrS initial;
    size_t totalNode;
    int *tables[4][2];
    
    operation readToken(char);
    void infixToPostfix();	//¡ﬂ¿ß«•«ˆ¿ª »ƒ¿ß«•«ˆ¿∏∑Œ ∫Ø»Ø
    void labelingNode(ptrS);	//≥ÎµÂø° ∂Û∫ß ∫Øºˆ ∫Œø©
    void makeNfa();		//NFA∫Ø»Ø
    void setTables(ptrS);	//state table¿« ≥ªøÎ¿ª √§øÏ¥¬ «‘ºˆ
    
public:
    nfa(string);	//ª˝º∫¿⁄
    ~nfa();		//µø¿˚¿∏∑Œ ª˝º∫µ» πËø≠∞˙ ≥ÎµÂ ¡¶∞≈
    void printStateTable();
    
};

operation nfa::readToken(char w)
{
    switch (w)
    {
        case 'a':
        case 'b':
            return operation::alphabet;
            break;
        case '(':
            return operation::Open;
            break;
        case ')':
            return operation::End;
            break;
        case '|':
            return operation::alternative;
            break;
        case '.':
            return operation::wildcards;
            break;
        case '*':
            return operation::kleene;
            break;
        case '+':
            return operation::positive;
            break;
        case 0:
            return operation::error;
            break;
        default:
            throw "«„øÎµ«¡ˆ æ ¿∫ πÆ¿⁄";
            return operation::error;
            break;
    }
}

void nfa::infixToPostfix()
{
    //∞˝»£ √º≈©
    {
        int check = -1;
        for (size_t cur = 0; cur < w.length(); cur++)
        {
            if (w[cur] == '|')
                if (w[cur + 1] != '(' && readToken(w[cur + 1]) != operation::alphabet)
                    throw "∞˝»£,«’¡˝«’ø¿∑˘!";
            
            if (w[cur] == '(') 	check++;
            else if (w[cur] == ')') check--;
        }
        if (check != -1) throw "∞˝»£ø¿∑˘!";
    }
    //'+' closure∏¶ '*' closure∑Œ ∫Ø»Ø
    for (size_t cur = 0; cur < w.length(); cur++)
    {
        if (w[cur] == '+')
        {
            w[cur] = '*'; // + --> *∫Ø»Ø
            string temp;
            int prev = cur - 1;
            if (w[prev] == ')')
            {
                int check = -1, search = cur - 1;
                while (search >= 0)
                {
                    if (w[search] == ')') check++;
                    else if (w[search] == '(') check--;
                    if (check == -1) break;
                    search--;
                }
                if (check != -1) throw "∞˝»£ ø¿∑˘";
                temp = w.substr(search, cur - search); //(w)∫πªÁ
            }
            else if (readToken(w[prev]) == operation::alphabet)
                temp = w[prev];
            else
                throw "+¿ßƒ° ø¿∑˘";
            
            w.insert(cur, temp);
        }
    }
    
    //concatenation¿ª ¿ß«— wildcard ª¿‘
    for (size_t cur = 0; cur < w.length(); cur++)
    {
        char next = w[cur + 1], now = w[cur];
        
        wPostfix += now;
        if ((now != '|' && now != '(')
            && (next == '(' || readToken(next) == operation::alphabet))
            wPostfix += '.';
    }
    
    //postFix
    string temp;
    stack<char> s;
    for (size_t cur = 0; cur < wPostfix.length(); cur++)
    {
        char token = wPostfix[cur];
        switch (readToken(token))
        {
            case operation::alternative:
            case operation::wildcards:
                while ((!s.empty()) && (readToken(token) <= readToken(s.top())))
                {
                    temp += s.top();
                    s.pop();
                }
                s.push(token);
                break;
                
            case operation::End:
                while (readToken(s.top()) != operation::Open)
                {
                    temp += s.top();
                    s.pop();
                }
                s.pop();
                break;
                
            case operation::Open:	s.push(token);	break;
            case operation::kleene:	temp += token;	break;
            default:	temp += token;	break;
        }
    }
    
    while (!s.empty())
    {
        temp += s.top();
        s.pop();
    }
    wPostfix = temp;	//»ƒ¿ßø¨ªÍ ¿˙¿Â
}

void nfa::makeNfa()//≥ÎµÂ∏¶ ø¨∞·«ÿ¡÷¥¬ «‘ºˆ
{
    ptrS createState(char);
    ptrS alternativeState(ptrS, ptrS);
    ptrS concatenationState(ptrS, ptrS);
    ptrS kleeneState(ptrS);
    
    stack<ptrS> nfaS;
    
    nfaS.push(createState('<')); // < -- Start
    
    ptrS left, right;
    for (size_t cur = 0; cur < wPostfix.length(); cur++)
    {
        switch (readToken(wPostfix[cur]))
        {
            case operation::alphabet:	nfaS.push(createState(wPostfix[cur]));	break;
            case operation::alternative:
                right = nfaS.top(); nfaS.pop();
                left = nfaS.top(); nfaS.pop();
                nfaS.push(alternativeState(left, right));
                break;
            case operation::wildcards:
                right = nfaS.top(); nfaS.pop();
                left = nfaS.top(); nfaS.pop();
                nfaS.push(concatenationState(left, right));
                break;
            case operation::kleene:
                right = nfaS.top(); nfaS.pop();
                nfaS.push(kleeneState(right));
                break;
        }
    }
    
    // ¡§ªÛ¿˚¿Ã∂Û∏È Ω√¿€¡°∞˙, ¡ˆ±›±Ó¡ˆ ø¨∞·µ» ≥ÎµÂ 2∞≥
    if (nfaS.size() != 2) throw "±∏πÆø¿∑˘";
    
    //≥≤æ∆¿÷¥¬ stack ¡¶∞≈
    right = nfaS.top(); nfaS.pop();
    left = nfaS.top(); nfaS.pop();
    
    left = concatenationState(left, right);
    right = createState('>'); // > -- final state
    initial = concatenationState(left, right);
}

void nfa::labelingNode(ptrS fa)
{
    if ((fa != NULL) && !(fa->visit))
    {
        fa->visit = true;
        fa->label = totalNode++;
        labelingNode(fa->right);
        labelingNode(fa->left);
    }
}

void nfa::setTables(ptrS fa)
{
    if ((fa != NULL) && (fa->visit != false))
    {
        fa->visit = false;
        if (fa->edge == '>') tables[3][0][fa->label] = 1;	//«ˆ¿Á ¿ßƒ°∞° FINAL STATE∂Û∏È
        
        if (fa->right != NULL)	//≥ÎµÂø° ø¨∞·µ» ¡÷∫Ø ≥ÎµÂ ≈Ωªˆ
        {
            switch (fa->right->edge)
            {
                case 'a':tables[0][0][fa->label] = fa->right->label; break;
                case 'b':tables[1][0][fa->label] = fa->right->label; break;
                case 'e': case '>': tables[2][0][fa->label] = fa->right->label; break;
            }
        }
        if (fa->left != NULL)
        {
            switch (fa->left->edge)
            {
                case 'a':tables[0][1][fa->label] = fa->left->label; break;
                case 'b':tables[1][1][fa->label] = fa->left->label; break;
                case 'e': case '>': tables[2][1][fa->label] = fa->left->label; break;
            }
        }
        setTables(fa->left);
        setTables(fa->right);
    }
}

ptrS createState(char a)	//ªı Ω∫≈◊¿Ã∆Æ∏¶ ª˝º∫«œ¥¬ «‘ºˆ
{
    ptrS newState = new state;
    newState->edge = a;
    return newState;
}

ptrS alternativeState(ptrS m1, ptrS m2)		//'|' ø¨ªÍ
{
    ptrS start, end;
    start = createState('e');
    end = createState('e');
    
    start->left = m1;
    start->right = m2;
    
    ptrS temp = m1;
    while (temp->right != NULL) temp = temp->right;
    temp->right = end;
    
    temp = m2;
    while (temp->right != NULL) temp = temp->right;
    temp->right = end;
    
    return start;
}
ptrS concatenationState(ptrS m1, ptrS m2)	//'.' ø¨ªÍ
{
    ptrS temp = m1;
    while (temp->right != NULL) temp = temp->right;
    temp->right = m2;
    return m1;
}
ptrS kleeneState(ptrS m)	//'*' ø¨ªÍ
{
    ptrS start, end;
    start = createState('e');
    end = createState('e');
    
    start->left = m;
    start->right = end;
    
    ptrS cur = m;
    while (cur->right != NULL) cur = cur->right;
    
    cur->right = end;
    end->left = start;
    
    return start;
}

nfa::nfa(string _w)
{
    w = _w;
    wPostfix = "";
    initial = NULL;
    totalNode = 0;
    
    if (w.length() == 1 && readToken(w[0]) != operation::alphabet) throw "±∏πÆø¿∑˘";
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            tables[i][j] = NULL;
    
    infixToPostfix();
    makeNfa();
    labelingNode(initial);
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            tables[i][j] = new int[totalNode];
    
    for (size_t i = 0; i < 4; i++)	//∏µÁ ø¨∞· ªÛ≈¬∏¶ 0¿∏∑Œ √ ±‚»≠
    {
        for (size_t j = 0; j < 2; j++)
            for (size_t k = 0; k < totalNode; k++)
                tables[i][j][k] = 0;
    }
    setTables(initial);
}

nfa::~nfa()		//µø¿˚ ª˝º∫µ» πËø≠∞˙ ≥ÎµÂ∏¶ ¡¶∞≈
{
    ptrS fa = initial;
    if ((fa != NULL) && !(fa->visit))
    {
        fa->visit = true;
        labelingNode(fa->right);
        labelingNode(fa->left);
        delete fa;
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            delete tables[i][j];
}

void nfa::printStateTable()//√‚∑¬
{
    printf("%6s | %5s | %5s | %5s | %6s\n", "STATE", "a", "b", "e", "NODE");
    for (int i = 0; i < 47; i++)
        cout << "=";
    cout << endl;
    for (size_t i = 0; i < totalNode; i++)
    {
        printf("%6d |", i);
        printf(" %2s %2s | %2s %2s | %2s %2s ",
               (tables[0][0][i]) ? to_string(tables[0][0][i]).c_str() : "X",
               (tables[0][1][i]) ? to_string(tables[0][1][i]).c_str() : "X",
               (tables[1][0][i]) ? to_string(tables[1][0][i]).c_str() : "X",
               (tables[1][1][i]) ? to_string(tables[1][1][i]).c_str() : "X",
               (tables[2][0][i]) ? to_string(tables[2][0][i]).c_str() : "X",
               (tables[2][1][i]) ? to_string(tables[2][1][i]).c_str() : "X");
        printf("| %6s\n", (i == 0) ? "START" : (tables[3][0][i] == 1) ? "FINAL" : " ");
        for (int i = 0; i < 47; i++)
            printf("-");
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        string RE;
        cout << "0¿ª ¿‘∑¬«œ∏È ¡æ∑·µÀ¥œ¥Ÿ" << endl;
        cout << "¡§±‘«•«ˆ ¿‘∑¬: ";
        cin >> RE;
        if (RE == "0") {
            break;
        }
        else {
            try {
                nfa NFA = nfa(RE);
                NFA.printStateTable();
            }
            catch (const char *e)
            {
                cout << e << endl;
            }
            system("pause");
            system("cls");
        }
    }
    
    return 0;
}
