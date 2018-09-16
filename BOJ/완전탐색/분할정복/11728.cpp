//
//  11728.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 20..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> res;
    int N, M;
    scanf("%d %d", &N, &M);
    
    while(N--){
        int temp;
        scanf("%d", &temp);
        res.push_back(temp);
    }
    while(M--){
        int temp;
        scanf("%d", &temp);
        res.push_back(temp);
    }
    sort(res.begin(), res.end());
    vector<int>::iterator it;
    for(it = res.begin(); it!=res.end(); it++)
        cout << *it << " ";
    
    return 0;
}
