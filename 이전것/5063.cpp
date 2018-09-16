//
//  5063.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, r, e, c;
    cin >> n;
    while (n--) {
        cin >> r >> e >> c;
        if (r < e - c)
            cout << "advertise" << '\n';
        else if (r == e - c)
            cout << "does not matter" << '\n';
        else
            cout << "do not advertise" << '\n';
    }
    return 0;
}
