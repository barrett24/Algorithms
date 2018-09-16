//
//  2594.cpp
//  baek
//
//  Created by Sean on 2018. 5. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include<iostream>
#include<algorithm>
using namespace std;

int d[721]={0,};

int main(){
    int N;
    int S,E,s,e;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d %d", &S, &E);
        s = (S/100 - 10)*60 + (S%100) - 10;
        e = (E/100 - 10)*60 + (E%100) + 10;
        for(int i=s; i<=e; i++) d[i] = 1;
    }
    int cnt=0, res=0;
    
    for(int i=0; i<=721;i++){
        if(d[i]==0) cnt++;
        if(d[i]==0 && d[i+1]==1){
            cnt++;
            res = max(cnt,res);
            cnt = 0;
        }
    }
    printf("%d", res);
    return 0;
}
