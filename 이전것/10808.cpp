//
//  10808.cpp
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
    for(int i ='a'; i<='z'; i++){
        cout << count(s.begin(), s.end(), i) << ' ';
    }//count(시작, 끝, 찾는 것) - 알고리즘 헤더
    cout << '\n';
    return 0;
}
