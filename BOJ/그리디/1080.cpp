//
//  1080.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 18..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
char a[51][51], b[51][51];
int N, M;

void rev(int x, int y){
    for(int i=x-1; i<=x+1; i++)
        for(int j=y-1; j<=y+1; j++){
            if(a[i][j] == '0')
                a[i][j] = '1';
            else if(a[i][j] == '1')
                a[i][j] = '0';
        }
}
bool check(){
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(a[i][j] != b[i][j])
                return false;
        }
    return true;
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", a[i]);
    for(int i=0; i<N; i++)
        scanf("%s", b[i]);
    
    int cnt = 0;
    
    for(int i=1; i<N-1; i++)
        for(int j=1; j<M-1; j++){
            if(a[i-1][j-1] != b[i-1][j-1]){
                rev(i,j);
                cnt++;
            }
        }
    if(check()==true) printf("%d", cnt);
    else printf("-1");
    return 0;
}
