//
//  1965.cpp
//  baek
//
//  Created by Sean on 2018. 1. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//
//  @@@@@@@@@@@@@@    LIS 알고리즘    @@@@@@@@@@@@@@

#include <iostream>
using namespace std;

int N;
int dp[1001]={0,};
int arr[1001]={0,};

int main(){
        cin >> N;
    for(int i = 1; i<=N; i++)
        cin >> arr[i];
    for(int i = 1; i<=N; i++){
        dp[i] = 1;
        for(int j = 1 ; j<=i; j++){
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] +1;
        }
    }
    int max = 0;
    for(int i = 1; i<=N; i++)
        if(max == 0 || max < dp[i])
            max = dp[i];
    cout << max << endl;
    return 0;
}
