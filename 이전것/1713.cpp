//
//  1713.cpp
//  baek
//
//  Created by Sean on 2018. 4. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K, temp;
vector<int> v;
queue<int> q;

int main(){
    scanf("%d", &N);
    scanf("%d", &K);
    v.resize(K);
    
    for(int i=0; i<K; i++){
        scanf("%d", &temp);
        q.push(temp);
    }
    return 0;
}
