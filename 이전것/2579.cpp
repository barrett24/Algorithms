//
//  2579.cpp
//  baek
//
//  Created by Sean on 2017. 8. 30..
//  Copyright © 2017년 Sean. All rights reserved.
//
/* 2차원 배열 이용
#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
int a[301];
int d[301][3];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    d[1][1] = a[1];
    for(int i=2; i<=n; i++){
        d[i][2] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
    }
    printf("%d\n", max(d[n][1],d[n][2]));
    return 0;
}*/
//1차원 베열 이용
#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
int a[301];
int d[301];
int main(){
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    d[1] = a[1];
    d[2] = a[1] + a[2];
    for(int i=3; i<=n; i++)
        d[i] = max(d[i-2]+a[i], d[i-3]+a[i]+a[i-1]);
    
    printf("%d", d[n]);
    return 0;
}
