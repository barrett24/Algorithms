//
//  10707.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, p;
    int x, y;
    cin >> a >> b >> c >> d >> p;
    x = a * p;
    if (c < p)
    {
        p -= c;
        y = b + d * p;
    }
    else
        y = b;
    int ans = x < y ? x : y;
    cout << ans << '\n';
}
