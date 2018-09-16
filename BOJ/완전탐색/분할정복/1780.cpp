//
//  1780.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 20..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
int arr[2200][2200];
int cnt_, cnt0, cnt1;

bool check(int x, int y, int x1, int y1){
    int st = arr[x][y];
    for(int i=x; i<x1; i++)
        for(int j=y; j<y1; j++)
            if(st != arr[i][j])
                return false;
    if(st==-1) cnt_++;
    else if(st==0) cnt0++;
    else if(st==1) cnt1++;
    return true;
}
void div(int x, int y, int N){
    if(check(x,y,x+N,y+N) == true)
        return;
    else if(check(x,y,x+N,y+N) == false){
        for(int i=x; i<x+N; i+=N/3)
            for(int j=y; j<y+N; j+=N/3)
                div(i, j, N/3);
    }
}
int main(){
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        for(int j=0 ; j<N; j++)
            scanf("%d", &arr[i][j]);
    div(0, 0, N);
    printf("%d\n%d\n%d\n", cnt_,cnt0,cnt1);
    return 0;
}
