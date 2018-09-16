//
//  10797.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int num, carNum, cnt = 0;
    cin >> num;
    for (int i = 0; i < 5; i++)
    {
        cin >> carNum;
        if (carNum == num)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
