//
//  9466_비재귀.cpp
//  baek
//
//  Created by Sean on 2017. 9. 16..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <cstdio>
int a[10001];
int d[10001];
int s[10001];
int n;

int dfs(int x, int cnt, int &step){
    while(1){
        if(d[x] != 0){
            if(step != s[x]) return 0;
            return cnt-d[x];
        }
        d[x] = cnt;
        s[x] = step;
        x = a[x];
        cnt += 1;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            d[i] = 0;
            s[i] = 0;
        }
        int ans;
        for(int i=1; i<<=n; i++){
            if(d[i] == 0){
                ans += dfs(i, 1, i);
            }
        }
        printf("%d\n", n-ans);
    }
    return 0;
}
