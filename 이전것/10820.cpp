//
//  10820.cpp
//  baek
//
//  Created by Sean on 2017. 8. 24..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    while (getline(cin, s)) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;
        for (char x: s)//for(데이터형 변수명 : 배열이나 문자열 컬렉션 변수명)
        {
            if (x >= 'a' && x <= 'z') {
                lower += 1;
            } else if (x >= 'A' && x <= 'Z') {
                upper += 1;
            } else if (x >= '0' && x <= '9') {
                number += 1;
            } else if (x == ' ') {
                space += 1;
            }
        }
        cout << lower << ' '<< upper << ' ';
        cout << number << ' ' << space << '\n';
    }
    return 0;
}
