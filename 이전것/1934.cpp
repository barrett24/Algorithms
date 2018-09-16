//
//  1934.cpp
//  baek
//
//  Created by Sean on 2017. 9. 2..
//  Copyright © 2017년 Sean. All rights reserved.
//
#include <iostream>
using namespace std;
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x%y);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int g = gcd(a,b);
        cout << a*b/g << '\n';
    }
    return 0;
}
