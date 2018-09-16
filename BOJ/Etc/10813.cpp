//
//  10813.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
int arr[101];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int j=1; j<=N; j++)
        arr[j] = j;
    
    while(M--){
        int a, b;
        scanf("%d %d", &a, &b);
        swap(arr[a], arr[b]);
    }
    for(int i=1; i<=N; i++)
        printf("%d ", arr[i]);
    return 0;
}
