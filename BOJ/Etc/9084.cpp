//
//  9084.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 6. 30..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
int coin[21];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
            scanf("%d", &coin[i]);
        scanf("%d", &M);
        int dp[10001]={0,};
        dp[0] = 1;
        for(int i=1; i<=N; i++)
            for(int j=coin[i]; j<=M; j++)
                dp[j] += dp[j-coin[i]];
        printf("%d\n", dp[M]);
    }
    return 0;
}
