//
//  10989.cpp
//  baek
//
//  Created by Sean on 2017. 9. 7..
//  Copyright © 2017년 Sean. All rights reserved.
//
// ********************
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[10001];
int main(){
    int n;
    scanf("%d", &n);
    int temp=0;
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        cnt[temp]+=1;
    }
    for(int i=1; i<=10000; i++){
        if(cnt[i] > 0){
            for(int j=0; j<cnt[i]; j++){
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
