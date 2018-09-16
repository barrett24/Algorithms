#include <iostream>
#include <stack>
#include <vector>
#include <conio.h>
#include <queue>
using namespace std;

struct nst
{
    vector<int> a[2], e;
    bool f=0;
};

vector<nst> nfa;

struct dst
{
    int a[2] = {-1,-1};
    bool f=0;
};

vector<dst> dfa;

stack<int> st;

int nfa_size, dfa_size;
string dispregex;

struct nst init_nfa_state;

struct dst init_dfa_state;

void custom_clear() {
    for(int i=0; i<100; i++) std::cout<<std::endl;
}

/***************************** regex to nfa ****************************/

string insert_concat(string regexp){
    string ret="";
    char c,c2;
    for(unsigned int i=0; i<regexp.size(); i++){
        c=regexp[i];
        if(i+1<regexp.size()){
            c2=regexp[i+1];
            ret+=c;
            if(c!='('&&c2!=')'&&c!='+'&&c2!='+'&&c2!='*'){
                ret+='.';
            }
        }
    }
    ret+=regexp[regexp.size()-1];
    return ret;
}

void character(int i)
{
    nfa.push_back(init_nfa_state);
    nfa.push_back(init_nfa_state);
    nfa[nfa_size].a[i].push_back(nfa_size+1);
    st.push(nfa_size);
    nfa_size++;
    st.push(nfa_size);
    nfa_size++;
}

void union_()
{
    nfa.push_back(init_nfa_state);
    nfa.push_back(init_nfa_state);
    int d = st.top(); st.pop();
    int c = st.top(); st.pop();
    int b = st.top(); st.pop();
    int a = st.top(); st.pop();
    nfa[nfa_size].e.push_back(a);
    nfa[nfa_size].e.push_back(c);
    nfa[b].e.push_back(nfa_size+1);
    nfa[d].e.push_back(nfa_size+1);
    st.push(nfa_size);
    nfa_size++;
    st.push(nfa_size);
    nfa_size++;
}

void concatenation()
{
    int d = st.top(); st.pop();
    int c = st.top(); st.pop();
    int b = st.top(); st.pop();
    int a = st.top(); st.pop();
    nfa[b].e.push_back(c);
    st.push(a);
    st.push(d);
}

void kleene_star()
{
    nfa.push_back(init_nfa_state);
    nfa.push_back(init_nfa_state);
    int b = st.top();
    st.pop();
    int a = st.top();
    st.pop();
    nfa[nfa_size].e.push_back(a);
    nfa[nfa_size].e.push_back(nfa_size+1);
    nfa[b].e.push_back(a);
    nfa[b].e.push_back(nfa_size+1);
    st.push(nfa_size);
    nfa_size++;
    st.push(nfa_size);
    nfa_size++;
}

void postfix_to_nfa(string postfix)
{
    for(unsigned int i=0; i<postfix.size(); i++)
    {
        switch(postfix[i])
        {
        case 'a':
        case 'b': character(postfix[i]-'a'); break;
        case '*': kleene_star(); break;
        case '.': concatenation(); break;
        case '+': union_();
        }
    }
}

void display_nfa()
{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Phase 1: regex to nfa conversion using thompson's construction algorithm\n";
    std::cout<<"------------------------------------------------------------------------\n";
    std::cout<<"State\t|\ta\t|\tb\t|\teps\t|accepting state|"<<std::endl;
    std::cout<<"------------------------------------------------------------------------\n";
    for(unsigned int i=0; i<nfa.size(); i++)
    {
        std::cout<<i<<"\t|\t";
        for(unsigned int j=0; j<nfa[i].a[0].size(); j++)std::cout<<nfa[i].a[0][j]<<' ';
        std::cout<<"\t|\t";
        for(unsigned int j=0; j<nfa[i].a[1].size(); j++)std::cout<<nfa[i].a[1][j]<<' ';
        std::cout<<"\t|\t";
        for(unsigned int j=0; j<nfa[i].e.size(); j++)std::cout<<nfa[i].e[j]<<' ';
        std::cout<<"\t|\t";
        if(nfa[i].f)std::cout<<"Yes"; else std::cout<<"No";
        std::cout<<"\t|\n";
    }
    std::cout<<"------------------------------------------------------------------------\n";
}

int priority(char c){
    switch(c){
        case '*': return 3;
        case '.': return 2;
        case '+': return 1;
        default: return 0;
    }
}

string regexp_to_postfix(string regexp)
{
    string postfix="";
    stack<char> op;
    char c;
    for(unsigned int i=0; i<regexp.size(); i++)
    {
        switch(regexp[i])
        {
            case 'a':
            case 'b':
                postfix+=regexp[i]; break;
            case '(':
                op.push(regexp[i]); break;
            case ')':
                while(op.top()!='('){
                    postfix+=op.top();
                    op.pop();
                }
                op.pop();
                break;
            default:
                while(!op.empty()){
                    c=op.top();
                    if(priority(c)>=priority(regexp[i])){
                        postfix+=op.top();
                        op.pop();
                    }
                    else break;
                }
                op.push(regexp[i]);
        }
        //std::cout<<regexp[i]<<' '<<postfix<<std::endl;
    }
    while(!op.empty())
    {
        postfix += op.top();
        op.pop();
    }
    return postfix;
}

/***************************** nfa to dfa ****************************/

void print_dfa(){
    std::cout<<std::endl;
    std::cout<<"NFA TO DFA CONVERSION"<<std::endl;
    std::cout<<"---------------------------------------------------------"<<std::endl;
    std::cout<<"STATE\t|\t"<<"a"<<"\t|\t"<<"b"<<"\t|\t"<<"FINAL"<<"\t|"<<std::endl;
    std::cout<<"---------------------------------------------------------"<<std::endl;
    for(int i=0;i<dfa.size();i++){
        std::cout<<i<<"\t|\t"<<dfa[i].a[0]<<"\t|\t"<<dfa[i].a[1]<<"\t|\t"<<dfa[i].f<<"\t|"<<std::endl;
    }
    std::cout<<"---------------------------------------------------------"<<std::endl;
}

void epsilon_closure(int state, set<int>&si){
    for(unsigned int i=0;i<nfa[state].e.size();i++){
        if(si.count(nfa[state].e[i])==0){
            si.insert(nfa[state].e[i]);
            epsilon_closure(nfa[state].e[i],si);
        }
    }
}

set<int> state_change(int c,set<int>&si){
    set<int> temp;
    if(c==1){
        for (std::set<int>::iterator it=si.begin(); it!=si.end(); ++it){
            for(unsigned int j=0;j<nfa[*it].a[0].size();j++){
                temp.insert(nfa[*it].a[0][j]);
            }
        }
    }
    else{
        for (std::set<int>::iterator it=si.begin(); it!=si.end(); ++it){
            for(unsigned int j=0;j<nfa[*it].a[1].size();j++){
                temp.insert(nfa[*it].a[1][j]);
            }
        }
    }
    return temp;
}

void print_menu(){
    std::cout<<"\n---------------------------------------\n";
    std::cout<<"Input Regex: "<<dispregex<<std::endl<<std::endl;
    std::cout<<"1. NFA\n";
    std::cout<<"2. Intermediate DFA\n";
    std::cout<<"3. Minimized DFA\n";
    std::cout<<"4. Simulation\n";
    std::cout<<"Press any other key to exit...\n\n";
}

void print(vector<tuple<int,int,bool> > min_dfa) {
    std::cout<<"---------------------------------------------------------"<<std::endl;
    std::cout<<"State\t|\tA\t|\tB\t|\tFinal\t|"<<std::endl;
    std::cout<<"---------------------------------------------------------"<<std::endl;
    for(int i=0; i<(int)min_dfa.size(); i++) {
        std::cout<<i<<"\t|\t";
        std::cout<<get<0>(min_dfa[i])<<"\t|\t";
        std::cout<<get<1>(min_dfa[i])<<"\t|\t";
        if(get<2>(min_dfa[i])) std::cout<<"Yes\t|"; else std::cout<<"No\t|";
        std::cout<<std::endl;
    }
    std::cout<<"---------------------------------------------------------"<<std::endl;
}

void simulate(int start_st,vector<tuple<int,int,bool> >min_dfa){
    print_menu();
    std::cout<<"Enter string : ";
    string input;
    cin.ignore();
    getline(cin,input);
    int curr_state,next_state;
    curr_state=start_st;
    custom_clear();
    std::cout<<"-----------------------------------------"<<std::endl;
    std::cout<<"Input\t|\tCurrent\t|\tNext\t|"<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
    for(unsigned i=0;i<input.size();i++){
        if(input[i]=='a')
            next_state=get<0>(min_dfa[curr_state]);
        else
            next_state=get<1>(min_dfa[curr_state]);
        std::cout<<input[i]<<"\t|\t"<<curr_state<<"\t|\t"<<next_state<<"\t|\n";
        curr_state=next_state;
    }
    std::cout<<"-----------------------------------------"<<std::endl;
    std::cout<<std::endl<<"Verdict: ";
    if(curr_state>=0&&get<2>(min_dfa[curr_state]))std::cout<<"Accepted"; else std::cout<<"Rejected";

    std::cout<<std::endl;
}


int main()
{
    custom_clear();
    string regexp,postfix;
    std::cout<<"Enter Regular Expression: ";
    std::cin>>regexp;
    dispregex=regexp;
    regexp=insert_concat(regexp);
    postfix = regexp_to_postfix(regexp);
    std::cout<<"Postfix Expression: "<<postfix<<std::endl;
    postfix_to_nfa(postfix);

    int final_state=st.top();st.pop();
    int start_state=st.top();st.pop();
    //std::cout<<start_state<<' '<<final_state<<std::endl;
    nfa[final_state].f=1;

    set<int> si;
    queue<set<int> > que;
    nfa_to_dfa(si,que,start_state);

    std::cout<<std::endl<<std::endl;

    pair<int,vector<tuple<int,int,bool> > > min_dfa_tmp = minimize_dfa(dfa);

    vector<tuple<int,int,bool> >  min_dfa= min_dfa_tmp.second;
    int start_st = min_dfa_tmp.first;

    getchar();
    custom_clear();


    while(1){
        print_menu();
        char choice;
        choice=getchar();
        custom_clear();

        switch(choice) {
        case '1':
            display_nfa();
            getchar();
            break;
        case '2':
            print_dfa();
            getchar();
            break;
        case '3':
            print(min_dfa);
            getchar();
            break;
        case '4':
            simulate(start_st,min_dfa);
            break;
        default:
            exit(EXIT_SUCCESS);
        }
    }
    std::cout<<std::endl<<std::endl;
    std::cout<<"Enter string : ";
    string input;
    cin.ignore();
    getline(cin,input);
    int curr_state,next_state;
    while(input!=""){
        //std::cout<<input<<std::endl;
        curr_state=start_st;
        for(unsigned i=0;i<input.size();i++){
            if(curr_state>=0){
                if(input[i]=='a')
                    next_state=get<0>(min_dfa[curr_state]);
                else
                    next_state=get<1>(min_dfa[curr_state]);
                if(next_state>=0){
                    std::cout<<input[i]<<" : State "<<curr_state<<" -> State "<<next_state<<std::endl;
                }
                else std::cout<<input[i]<<" : State "<<curr_state<<" -> Trap State"<<std::endl;
            }
            else std::cout<<input[i]<<" : Trapped"<<std::endl;
            curr_state=next_state;
        }
        if(curr_state>=0&&get<2>(min_dfa[curr_state]))std::cout<<"accepted"; else std::cout<<"rejected";
        std::cout<<std::endl<<std::endl;
        std::cout<<"Enter string : ";
        getline(cin,input);
    }
    return 0;
}
