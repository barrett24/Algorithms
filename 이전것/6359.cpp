//
//  6359.cpp
//  baek
//
//  Created by Sean on 2018. 2. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int T;
    int N;
    cin >> T;
    while(T--){
        cin >> N;
        int cnt = 0;
        int *dp = new int[N+1];
        for(int i=1; i<=N; i++)
            dp[i] = 0;//열림
        for(int i=2; i<=N; i++){
            for(int j=1; i*j <= N; j++){
                if(dp[i*j] == 0)
                    dp[i*j] = 1;
                else if(dp[i*j] == 1)
                    dp[i*j] = 0;
            }
        }
        for(int i=1; i<=N; i++){
            if(dp[i] == 0)
                cnt++;
        }
        cout << cnt << endl;
        delete[] dp;
    }
    return 0;
}
