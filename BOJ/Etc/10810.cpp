//
//  10810.cpp
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
    while(M--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        for(int i=a; i<=b; i++)
            arr[i] = c;
    }
    for(int i=1; i<=N; i++)
        printf("%d ", arr[i]);
    return 0;
}
