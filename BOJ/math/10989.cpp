//
//  10989.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 16..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int N;
    scanf("%d", &N);
    v.resize(10001);
    
    while(N--){
        int temp;
        scanf("%d", &temp);
        v[temp]++;
    }
    //sort(v.begin(), v.begin()+v.size());
    for(int i=0; i<v.size(); i++){
        if(v[i] == 0) continue;
        if(v[i] != 0){
            while(v[i]--) printf("%d\n", i);
        }
    }
    return 0;
}
