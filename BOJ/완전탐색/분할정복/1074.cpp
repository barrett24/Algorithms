//
//  1074.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 21..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;
int N, r, c;
int cnt;

void Z(int x, int y, int len){
    if(x==r && y==c){
        printf("%d", cnt);
        return;
    }
    if(len == 1){
        cnt++;
        return;
    }
    if(!(x<=r && r<x+len && y<=c && c<y+len)){
        cnt+=len*len;
        return;
    }
    Z(x,y,len/2);
    Z(x,y+len/2,len/2);
    Z(x+len/2,y,len/2);
    Z(x+len/2,y+len/2,len/2);
}
int main(){
    scanf("%d %d %d", &N, &r, &c);
    int len = pow(2,N);
    Z(0,0,len);
    return 0;
}
