//
//  2667.cpp
//  baek
//
//  Created by Sean on 2018. 5. 4..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

char data[26][26];
int cnt[25];
int N;
int ans;
const int x[] = {0,0,1,-1};
const int y[] = {-1,1,0,0};

void dfs(int a, int b){
    data[a][b] = '0';
    for(int i=0; i<4; i++){
        if(a+x[i] >= 0 && a+x[i] < N && b+y[i] >= 0 && b+y[i] <N)
            if(data[a+x[i]][b+y[i]] == '1'){
                cnt[ans]++;
                dfs(a+x[i], b+y[i]);
            }
    }
}
int main(){
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
            scanf("%s",data[i]);
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(data[i][j] == '1')
                ans = ans + 1;
                cnt[ans]++;
                dfs(i,j);
        }
    
    printf("%d\n", ans);
    sort(cnt, cnt+ans);
    for(int i=1; i<=ans; i++)
        printf("%d\n", cnt[i]);
    return 0;
}
