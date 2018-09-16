//
//  10974.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 7..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long fact[21] = {1};
bool check[21] = {false};

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i=1; i<N; i++)
        fact[i] = fact[i-1] * i;
    int a;
    scanf("%d", &a);
    
    if(a==1){
        long long num;
        scanf("%lld", &num);
        vector<int> v;
        for(int i=0; i<N; i++){
            for(int j=1; j<=N; j++){
                if(check[j] == true)
                    continue;
                if(fact[N-i-1] < num)
                    num -= fact[N-i-1];
                else{
                    check[j] = true;
                    v.push_back(j);
                    break;
                }
            }
        }
        for(int x : v) printf("%d ",x);
        v.clear();
    }else if(a == 2){
        vector<int> v(N);
        long long cnt = 0;
        for(int i=0; i<N; i++)
            scanf("%lld", &v[i]);
        for(int i=0; i<N; i++){
            for(int j=1; j<v[i]; j++){
                if(check[j] == true)
                    continue;
                cnt += fact[N-i-1];
            }
            check[v[i]] = true;
        }
        printf("%lld", cnt+1);
        v.clear();
    }
    return 0;
}
