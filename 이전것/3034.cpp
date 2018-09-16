//
//  3034.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    double tmp = sqrt(w*w+h*h);
    for (int i = 0; i < n; i++) {
        int stick;
        cin >> stick;
        if (stick <= tmp)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
    return 0;
}
