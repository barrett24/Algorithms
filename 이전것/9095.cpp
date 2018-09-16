//
//  9095.cpp
//  baek
//
//  Created by Sean on 2017. 8. 25..
//  Copyright © 2017년 Sean. All rights reserved.
//
#include<iostream>
int dp[11];
//dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
int main(){
    dp[0] = 1;
    for(int i=1; i<=10; i++){
        if(i-1 >= 0) dp[i] += dp[i-1];
        if(i-2 >= 0) dp[i] += dp[i-2];
        if(i-3 >= 0) dp[i] += dp[i-3];
    }
    int cnt;
    std::cin >> cnt;
    while(cnt--){
        int n;
        std::cin >> n;
        std::cout << dp[n] <<std::endl;
    }
    return 0;
}
