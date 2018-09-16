//
//  10809.cpp
//  baek
//
//  Created by Sean on 2017. 8. 24..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    
    for(int i='a'; i<='z'; i++){
        auto p = find(s.begin(), s.end(), i);
        if(p == s.end()){
            cout << -1 << ' ';
        }else{
            cout << (p-s.begin()) << ' ';
        }
    }
    cout << '\n';
    return 0;
}
