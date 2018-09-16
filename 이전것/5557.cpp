//
//  5557.cpp
//  baek
//
//  Created by Sean on 2018. 5. 24..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
typedef long long ll;
ll d[102];
ll dp[102][21];

int main(){
    int N, res;
    scanf("%d", &N);
    
    for(int i=1; i<N; i++){
        scanf("%lld", &d[i]);
    }
    scanf("%d", &res);
    dp[0][0]=1;
    
    for(int i=1; i<N; i++){
        for(int j=0; j<=20; j++){
            if(j+d[i] <= 20){
                dp[i][j + d[i]] += dp[i-1][j];
            }
            if(i>1 && j - d[i] >= 0){
                dp[i][j - d[i]] += dp[i-1][j];
            }
        }
    }
    printf("%lld", dp[N-1][res]);
    return 0;
}
