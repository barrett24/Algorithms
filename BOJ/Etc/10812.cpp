//
//  10812.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int arr[101];

void cir(int a, int b, int c){
    queue<int> q;
    int mid = c;
    
    for(int i=mid; i<=b; i++){
        q.push(arr[i]);
    }
    for(int i=a; i<mid; i++){
        q.push(arr[i]);
    }
    for(int j=a; j<=b; j++){
        arr[j] = q.front();
        q.pop();
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int j=1; j<=N; j++)
        arr[j] = j;
    while(M--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        cir(a, b, c);
    }
    for(int i=1; i<=N; i++)
        printf("%d ", arr[i]);
    return 0;
}
