//
//  1149.cpp
//  baek
//
//  Created by Sean on 2017. 12. 30..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][4], data[1001][4], N;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=3; j++)
            cin >> data[i][j];
    for(int i=1; i<=3; i++)
        dp[1][i] = data[1][i];
    for (int i = 2; i <= N; i++)
        for (int j = 1; j <= 3; j++)
        {
            
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + data[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + data[i][2];
            dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + data[i][3];
        }
    cout << min(dp[N][1], min(dp[N][2], dp[N][3]));

    return 0;
}
