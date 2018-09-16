//
//  11729.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 21..
//  Copyright © 2018년 siyoung Choi. All rights reserved.


//  재귀호출 감이 좀 안잡힘

#include <iostream>
#include <cmath>
using namespace std;

void hano(int N, int st, int mid, int go){
    if(N==1){
        printf("%d %d\n", st, go);
    }else{
        hano(N-1, st, go, mid);
        printf("%d %d\n", st, go);
        hano(N-1, mid, st, go);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n",(int)pow(2, N)-1);
    hano(N, 1, 2, 3);
    return 0;
}
