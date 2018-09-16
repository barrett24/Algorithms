//
//  12790.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int a[4], a1,b,t,f;
int main() {
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < 4; i++)
        {
            cin >> a1;
            a[i] += a1;
        }
        if (a[2] < 0)
            a[2] = 0;
        if (a[0] < 1)
            a[0] = 1;
        if (a[1] < 1)
            a[1] = 1;
        f = a[0] +5 * a[1] + 2*a[2] + 2*a[3];
        cout << f << '\n';
        
    }
}
