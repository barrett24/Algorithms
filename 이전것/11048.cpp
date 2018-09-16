//
//  11048.cpp
//  baek
//
//  Created by Sean on 2018. 1. 9..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int a[1005][1005];
int dp[1005][1005];
int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        dp[i][j]=max({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+a[i][j];
    
    printf("%d",dp[n][m]);
    return 0;
}
/*
 #include <stdio.h>
 inline int max(int a, int b) { return a > b ? a : b; }
 int i, j, n, m, k, dp[1001];
 int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
 for (j = 1; j <= m; j++) {
 scanf("%d", &k);
 dp[j] = max(dp[j - 1], dp[j]) + k;
 }
	}
	printf("%d", dp[m]);
	return 0;
 }
*/
