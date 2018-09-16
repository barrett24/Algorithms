//
//  5554.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int m, sec;
int total = 0;

int main(){
    int n = 4;
    int temp;
    while(n--){
        cin >> temp;
        total += temp;
    }
    if(total < 60){
        m = 0;
        sec = total;
    }else{
        m = total/60;
        sec = total%60;
    }
    cout << m << endl << sec << endl;
    return 0;
}
