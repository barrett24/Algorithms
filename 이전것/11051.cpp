//
//  11051.cpp
//  baek
//
//  Created by Sean on 2018. 2. 20..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n, k;
    int dp[1001][1001];
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=i; j++){
            if(j==0 || j==n)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
            if(i==n && j==k)
                break;
        }
    cout << dp[n][k] << endl;
    return 0;
}
