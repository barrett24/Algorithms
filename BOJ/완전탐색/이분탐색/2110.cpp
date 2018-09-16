//
//  2110.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 23..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,C;
vector<int> v;

int main(){
    scanf("%d %d", &N, &C);
    v.resize(N);
    
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        v[i] = temp;
    }
    sort(v.begin(), v.begin()+v.size());
    int left = 1, right = v[N-1] - v[0];
    int result=0;
    
    while(left <= right){
        int mid = (left+right) / 2;
        int begin = v[0];
        int cnt = 1;
        
        for(int i=1; i<N; i++){
            if(v[i] - begin >= mid){
                cnt++;
                begin = v[i];
            }
        }
        if(cnt >= C){
            result = mid;
            left = mid + 1;
        }else right = mid-1;
    }
    printf("%d\n", result);
    return 0;
}
