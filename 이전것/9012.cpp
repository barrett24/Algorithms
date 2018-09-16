//
//  9012.cpp
//  baek
//
//  Created by Sean on 2017. 8. 22..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string val(string s){
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]== '('){
            cnt += 1;
        }else if(s[i]==')'){
            cnt -= 1;
        }
        if (cnt < 0) {
            return "NO";
        }
    }
    if(cnt==0){
        return "YES";
    }else{
        return "NO";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << val(s) << endl;
    }
    return 0;
}
