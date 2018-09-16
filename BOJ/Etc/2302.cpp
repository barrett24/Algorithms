//
//  2302.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 1..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
long long seat[41];
long long ans = 1;

void fibo(){
    seat[0] = 1;
    seat[1] = 1;
    for(int i=2; i<=40; i++)
        seat[i] = seat[i-1] + seat[i-2];
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int temp, flag=0;
    fibo();
    while(m--){
        scanf("%d", &temp);
        ans *= seat[temp-flag-1];
        flag = temp;
    }
    ans *= seat[n-flag];
    printf("%lld", ans);
    return 0;
}
