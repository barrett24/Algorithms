//
//  1201.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 18..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<int> v;
    
    if(N+1 >= M+K && N <= M*K){
        for(int i=1; i<=N; i++)
            v.push_back(i);
        reverse(v.begin(), v.begin()+K);
        if(M>1){
            int a[M-1];
            for(int i=0; i<M-1; i++)
                a[i] = (N-K)/(M-1);
            int temp = (N-K)%(M-1);
            for(int i=0; i<temp; i++)
                a[i]++;
            vector<int>::iterator it = v.begin()+K;
            for(int i=0; i<M-1; i++){
                reverse(it, it+a[i]);
                it+=a[i];
            }
        }
        for(int i=0; i<N; i++)
            printf("%d ", v[i]);
    }else printf("-1");
    return 0;
}
