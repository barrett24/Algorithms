//
//  10984.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
double g,sg;
int c,sc,t, n;
int main() {
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        sc = 0;
        sg = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> c >> g;
            sc += c;
            sg += c * g;
        }
        printf("%d %.1f\n", sc, sg / sc);
    }
}
