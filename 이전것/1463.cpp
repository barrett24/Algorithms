//
//  dpdp.cpp
//  baek
//
//  Created by Sean on 2017. 8. 24..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[1000001];

int data(int n){
    dp[1]=0;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+1;
        if(i%2 == 0 && dp[i] > dp[i/2]+1)
            dp[i] = dp[i/2]+1;
        if(i%3 == 0 && dp[i] > dp[i/3]+1)
            dp[i] = dp[i/3]+1;
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << data(n) << endl;
    return 0;
}
