//
//  2193.cpp
//  baek
//
//  Created by Sean on 2017. 8. 29..
//  Copyright © 2017년 Sean. All rights reserved.
//이친수

#include <iostream>
using namespace std;
long long dp[91];
int main(){
    int n;
    cin >> n;
    dp[1] = 1, dp[2] = 1;
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    cout << dp[n] << endl;
    return 0;
}
