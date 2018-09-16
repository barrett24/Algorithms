//
//  11049.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 1..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++){
        int r, c;
        scanf("%d %d",&r, &c);
        v.push_back(make_pair(r,c));
    }
    return 0;
}
