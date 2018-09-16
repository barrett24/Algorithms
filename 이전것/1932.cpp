//
//  1932.cpp
//  baek
//
//  Created by Sean on 2017. 12. 30..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501], data[501][501], N;
int main(){
    int temp;
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=i; j++){
            cin >> temp;
            data[i][j] =temp;
        }
    dp[1][1] = data[1][1];
    for (int i = 2; i <= N; i++){
        for (int j = 1; j <= i; j++){
            if (j == 1){
                dp[i][j] = dp[i - 1][j]+data[i][j];
            }
            else if (j == i){
                dp[i][j] = dp[i - 1][j - 1] + data[i][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j] + data[i][j], dp[i - 1][j - 1] + data[i][j]);
            }
        }
    }
    int maxNum = dp[N][1];
    for (int i = 2; i <= N; i++){
        if (dp[N][i] > maxNum){
            maxNum = dp[N][i];
        }
    }
    cout << maxNum << endl;
    
    return 0;
}
