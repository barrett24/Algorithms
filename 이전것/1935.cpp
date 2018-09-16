//
//  1935.cpp
//  baek
//
//  Created by Sean on 2018. 4. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

/*#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char> sy;
    stack<char> sp;
    string str;
    int a[26];
    int N;
    
    cin >> N;
    scanf("%d", &N);
    cin >> str;
    for(int i=0; i<N; i++)
        cin >> a[i];
    
    for(int i=0; i<=str.size(); i++){
        if(str[i]=='*'||str[i]=='+'||str[i]=='/'||str[i]=='-')
            sy.push(i);
        else{
            sp.push(i);
        }
    }
    while(sp.size()!=1){
        if(sy.top()=='*'){
            double q = a[sp.top()-'A'];
            sp.pop();
            double w = a[sp.top()-'A'];
            sp.pop();
            sp.push(q*w);
            sy.pop();
        }else if(sy.top()=='/'){
            double q = a[sp.top()-'A'];
            sp.pop();
            double w = a[sp.top()-'A'];
            sp.pop();
            sp.push(q/w);
            sy.pop();
        }else if(sy.top()=='-'){
            double q = a[sp.top()-'A'];
            sp.pop();
            double w = a[sp.top()-'A'];
            sp.pop();
            sp.push(q-w);
            sy.pop();
        }else if(sy.top()=='+'){
            double q = a[sp.top()-'A'];
            sp.pop();
            double w = a[sp.top()-'A'];
            sp.pop();
            sp.push(q+w);
            sy.pop();
        }
    }
    cout << sp.top() << endl;
    return 0;
}*/

#include<cstdio>
#include<stack>
#include<cstring>
#define MAX 100000
using namespace std;
typedef long double ld;
ld value[26] = {0,};
char expr[MAX] = {0,};
int main(){
    ld result = 0;
    stack<ld> s;
    int N = 0; scanf("%d", &N);
    scanf("%s", expr);
    for(int i = 0 ; i < N ; i++){
        scanf("%Lf",&value[i]);
    }
    int slen;
    slen = strlen(expr);
    for(int i = 0 ; i < slen ; i++){
        ld tmp;
        if('A' <= expr[i] && expr[i] <= 'Z'){
            s.push( value[expr[i] - 'A'] );
        }else{
            tmp = s.top(); s.pop();
            switch(expr[i]){
                case '+': tmp = tmp + s.top(); s.pop(); break;
                case '-': tmp = s.top() - tmp; s.pop(); break;
                case '*': tmp = tmp * s.top(); s.pop(); break;
                case '/': tmp = s.top() / tmp; s.pop(); break;
            }
            s.push(tmp);
        }
        result = s.top();
    }
    printf("%.2Lf\n",result);
    return 0;
}
