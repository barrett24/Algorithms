//
//  10870.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
int F[20];

void fibo(){
    F[0] = 0;
    F[1] = F[2] = 1;
    for(int i=3; i<=20; i++)
        F[i] = F[i-1] + F[i-2];
}
int main(){
    int N;
    scanf("%d", &N);
    fibo();
    printf("%d", F[N]);
    return 0;
}
