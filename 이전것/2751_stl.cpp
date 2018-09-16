//
//  2751.cpp
//  baek
//
//  Created by Sean on 2017. 9. 5..
//  Copyright © 2017년 Sean. All rights reserved.
//  while 보단 for가 빠름

#include <cstdio>
#include <algorithm> // sort()
using namespace std;
int d[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &d[i]);
    }
    sort(d,d+n);
    for(int i=0; i<n; i++){
        printf("%d\n", d[i]);
    }
    return 0;
}
