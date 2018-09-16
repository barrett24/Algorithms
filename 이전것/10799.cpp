//
//  main.cpp
//  baek
//
//  Created by Sean on 2017. 8. 22..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    unsigned int n = s.size();
    
    stack<int> a;
    int bar=0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            a.push(i);
        }else if(a.top()+1 == i){
            a.pop();
            bar += a.size();
        }else{
            a.pop();
            bar += 1;
        }
    }
    cout << bar << endl;
    return 0;
}
