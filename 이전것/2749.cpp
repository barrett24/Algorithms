//
//  2749.cpp
//  baek
//
//  Created by Sean on 2018. 2. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
const int mod = 1000000;
const int p = mod/10*15;
int fibo[p] = {0,1};
int main() {
    long long n;
    cin >> n;
    for (int i=2; i<p; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= mod;
    }
    cout << fibo[n%p] << '\n';
    return 0;
}
