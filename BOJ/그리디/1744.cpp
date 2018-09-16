//
//  1744.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 11..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

int main(){
    int N;
    scanf("%d", &N);
    int MAX = N;
    while(N--){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.begin()+v.size());
    int sum = 0;
    int i , j;
    for(i=0; i<MAX-1 && v[i+1]<1; i+=2){
        sum += v[i] * v[i+1];
    }
    for(j=MAX-1; j>0 && v[j-1]>1; j-=2){
        sum += v[j] * v[j-1];
    }
    for(;i<=j; i++)
        sum += v[i];
    printf("%d", sum);
    return 0;
}
