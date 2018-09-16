//
//  10866.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n,a=0,b=0;
    cin >> n;
    for (int i = 0,j; i < n; i++) {
        cin >> j;
        if (j)
            a++;
        else
            b++;
    }
    cout << (a > b ? "Junhee is cute!" : "Junhee is not cute!");
    return 0;
}
