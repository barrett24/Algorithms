//
//  1012.cpp
//  baek
//
//  Created by Sean on 2018. 5. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int v[51][51];
int T, M, N, K;
const int x[] = {0,0,1,-1};
const int y[] = {-1,1,0,0};

void dfs(int a, int b){
    v[a][b] = 0;
    for(int i=0; i<4; i++){
        if(a+x[i] >= 0 && a+x[i] < M && b+y[i] >= 0 && b+y[i] <N)
            if(v[a+x[i]][b+y[i]] == 1){
                dfs(a+x[i], b+y[i]);
        }
    }
}

int main(){
    scanf("%d", &T);
    
    while(T--){
        int cnt = 0;
        scanf("%d %d %d", &M, &N, &K);
        
        for(int k=0; k<K; k++){
            int temp1, temp2;
            scanf("%d %d", &temp1, &temp2);
            v[temp1][temp2] = 1;
        }
    
        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++){
                if(v[i][j]==1){
                    cnt++;
                    dfs(i,j);
                }
            }
        printf("%d\n", cnt);
    }
    return 0;
}
