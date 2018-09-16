//
//  11004.cpp
//  baek
//
//  Created by Sean on 2017. 9. 8..
//  Copyright © 2017년 Sean. All rights reserved.
//
//*********************퀵소트를 사용해서도 풀어보기
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int d[5000000];
int main(){
    int n,k;
    scanf("%d %d", &n,&k);
    k-=1;
    for(int i=0; i<n; i++){
        scanf("%d", &d[i]);
    }
    nth_element(d,d+k,d+n);
    printf("%d\n", d[k]);
    return 0;
}
