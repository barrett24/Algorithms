//
//  2875.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 16..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int N, M, K;
    int team = 0;
    scanf("%d %d %d", &N, &M, &K);
    
    while(N>=2 && M>=1){
        N-=2; M-=1;
        team++;
    }
    while(K > M+N){
        N+=2; M+=1;
        team--;
    }
    printf("%d", team);
    return 0;
}
