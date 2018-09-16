//
//  11725.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 1..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
vector<int> v[100000];
int arr[100000];

void DFS(int p){
    for(int next: v[p]){
        if(arr[next] == -1){
            arr[next] = p;
            DFS(next);
        }
    }
}

int main(){
    scanf("%d", &N);
    memset(arr, -1, sizeof(arr));
    
    for(int i=1; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    DFS(0);
    for(int i=1; i<N; i++)
        printf("%d\n", arr[i]+1);
    return 0;
}
