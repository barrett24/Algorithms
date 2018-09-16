//
//  11066.cpp
//  baek
//
//  Created by Sean on 2018. 2. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 0x7fffffff/2
using namespace std;

int arr[501];
int dp[501][501];
int sum[501];

int func(int start, int end){
    if(start >= end)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];
    if(end == start+1)
        return arr[start] + arr[end];
    
    dp[start][end] = MAX;
    for(int i=start; i<=end; i++){
        int temp = func(start,i) + func(i+1, end) + sum[end]-sum[start-1];
        dp[start][end] = min(dp[start][end], temp);
    }
    return dp[start][end];
}

int main(){
    int T, N;
    cin >> T;
    
    while(T--){
        cin >> N;
        for(int i=1; i<=N; i++){
            sum[i] = 0;
            for(int j=1; j<=N; j++)
                dp[i][j] = -1;
        }
        
        for(int i=1; i<=N; i++){
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        
        cout << func(1, N) << endl;
    }
    return 0;
}
