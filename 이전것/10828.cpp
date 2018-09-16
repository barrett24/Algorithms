//
//  main.cpp
//  baek
//
//  Created by Sean on 2017. 8. 20..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    stack<int> k;
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            k.push(num);
        }else if (cmd == "top") {
            cout << (k.empty() ? -1 : k.top()) << endl;
        }else if (cmd == "size") {
            cout << k.size() << endl;
        }else if (cmd == "empty") {
            cout << k.empty() << endl;
        }else if (cmd == "pop") {
            cout << (k.empty() ? -1 : k.top()) << endl;
            if (!k.empty()){
                k.pop();
            }
        }
    }
    return 0;
}
