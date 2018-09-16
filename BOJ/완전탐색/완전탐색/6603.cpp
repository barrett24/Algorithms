//
//  6603.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 3..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
// 나동빈 -> 유투브!

#include <iostream>
using namespace std;
int lotto[14];
int check[14];
int K;

void dfs(int start, int def){
    if(def == 7){
        for(int i=1; i<=6; i++) printf("%d ", check[i]);
        printf("\n");
        return;
    }
    for(int i=start; i<=K; i++){
        check[def] = lotto[i];
        dfs(i+1, def+1);
    }
}

int main(){
    while(1){
        scanf("%d", &K);
        if(K==0) break;
        else{
            for(int i=1; i<=K; i++) scanf("%d", &lotto[i]);
            dfs(1, 1);
            printf("\n");
        }
    }
    return 0;
}
