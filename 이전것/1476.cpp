//
//  1476.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int E, S, M;
    int e, s, m;
    int year = 0;
    
    cin >> E >> S >> M;
    while(1){
        e = year % 15 + 1;
        s = year % 28 + 1;
        m = year % 19 + 1;
        year++;
        if(E==e && S==s && M==m)
            break;
    }
    cout << year << endl;
    return 0;
}
