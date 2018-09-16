//
//  1931.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 8..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<pair<int, int>> v;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        int i1, i2;
        scanf("%d %d", &i1, &i2);
        v.push_back(make_pair(i2, i1));//끝나는 시간 기준
    }
    sort(v.begin(), v.begin()+N);
    
    int cnt = 0, point = 0;
    for(int i=0; i<N; i++){
        if(v[i].second >= point){
            cnt++;
            point = v[i].first;
        }
    }
    printf("%d", cnt);
    return 0;
}
