//
//  10811.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int arr[101];

void rev(int a, int b){
    stack<int> s;
    for(int i=a; i<=b; i++){
        s.push(arr[i]);
    }
    for(int j=a; j<=b; j++){
        arr[j] = s.top();
        s.pop();
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int j=1; j<=N; j++)
        arr[j] = j;
    while(M--){
        int a, b;
        scanf("%d %d", &a, &b);
        rev(a, b);
    }
    for(int i=1; i<=N; i++)
        printf("%d ", arr[i]);
    return 0;
}
