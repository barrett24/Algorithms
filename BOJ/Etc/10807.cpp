//
//  10807.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<int> v;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    vector<int>::iterator it;
    int K, cnt=0;
    scanf("%d", &K);
    for(it = v.begin(); it != v.end(); it++)
        if(*it == K) cnt++;
    printf("%d", cnt);
    return 0;
}
