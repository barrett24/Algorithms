//
//  10815.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    vector<int> v;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int temp;
        scanf("%d", &temp);
        int ans = binary_search(v.begin(), v.end(), temp);
        printf("%d ", ans);
    }
    return 0;
}
