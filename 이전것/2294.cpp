//
//  2294.cpp
//  baek
//
//  Created by Sean on 2018. 5. 2..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    int arr[100];
    int i, j;
    int dp[10001];
    
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i <= k; i++) {
        dp[i] = k+1;
    }
    
    dp[0] = 0;
    for (i = 0; i < n; i++) {
        for (j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]]+1);
        }
    }
    
    if (dp[k] == k+1) {
        printf("-1");
    }
    else {
        printf("%d", dp[k]);
    }
    return 0;
}
