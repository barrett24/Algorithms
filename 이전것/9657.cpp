//
//  9657.cpp
//  baek
//
//  Created by Sean on 2018. 5. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int n;
    cin >> n;
    
    if (n == 1 || n == 3 || n == 4) {
        cout << "SK";
        return 0;
    }
    
    dp[1] = 1;dp[2] = 0;dp[3] = 1;dp[4] = 1;
    
    for (int i = 5; i <= 1000; i++) {
        if (dp[i - 1] + dp[i - 3] + dp[i - 4] < 3)
            dp[i] = 1;
        else dp[i] = 0;
    }
    if (dp[n] == 1)
        cout << "SK";
    else cout << "CY";
    
    return 0;
}
