//
//  1309.cpp
//  baek
//
//  Created by Sean on 2018. 2. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[100001][3] = {0,};
int mod = 9901;

int main()
{
    int n;
    
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    
    cin >> n;
    
    for (int i = 2; i <= n + 1; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    
    cout << dp[n + 1][0];
    
    return 0;
}
