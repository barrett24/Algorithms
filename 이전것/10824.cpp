//
//  10824.cpp
//  baek
//
//  Created by Sean on 2017. 8. 24..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(c) + to_string(d);
    
    long long sum1 = stoll(s1);
    long long sum2 = stoll(s2);
    
    cout << sum1 + sum2 << endl;
    return 0;
}
