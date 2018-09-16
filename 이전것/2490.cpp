//
//  2490.cpp
//  baek
//
//  Created by Sean on 2018. 2. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int cnt = 0, arr[4];
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
            if (arr[i] == 0) //배의 개수
                cnt++;
            
        }
        switch (cnt)
        {
            case 0:
                cout << "E" << '\n'; break;
            case 1:
                cout << "A" << '\n'; break;
            case 2:
                cout << "B" << '\n'; break;
            case 3:
                cout << "C" << '\n'; break;
            case 4:
                cout << "D" << '\n'; break;
        }
        cnt = 0;
    }
}
