//
//  2718.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[10000];
int main() {
    
    int t;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    
    for (int i = 4; i <= 100; i++) {
        int temp = dp[i-2] * 4 + dp[i-1];
        
        for (int j = 3; j <= i; j++) {
            if (j & 1) {
                temp += dp[i - j] * 2;
            }
            else {
                temp += dp[i - j] * 3;
            }
        }
        
        dp[i] = temp;
        
    }
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
    
    
    return 0;
}
