//
//  10973.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 7..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

int main(){
    int N;
    scanf("%d",&N);
    v.resize(N);
    for(int i=0; i<N; i++){
        scanf("%d", &v[i]);
    }
    if(prev_permutation(v.begin(), v.end())){
        for(int i=0; i<N ;i++)
            printf("%d ", v[i]);
    }else printf("-1");
    return 0;
}
