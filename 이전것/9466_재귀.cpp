//
//  9466.cpp
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
//1.혼자할때 i == A[i]
//2.여러명 P1=>P2 ... Pk=>p1
//이미방문한 점 => 사이클 (사이클이 되면 조를 짤 수 있다)

int dfs(int x, int cnt, int &step){
    if(d[x] != 0){
        if(step != s[x]){
            return 0;
        }
        return cnt-d[x];
    }
    d[x] = cnt;
    s[x] = step;
    return dfs(a[x], cnt+1, step);
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
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(d[i] == 0){
                ans += dfs(i, 1, i);
            }
        }
        printf("%d\n", n-ans);
    }
    return 0;
}
