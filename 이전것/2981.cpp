//
//  2981.cpp
//  baek
//
//  Created by Sean on 2018. 4. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    long long temp;
    vector<long long> v;
    scanf("%d", &N);
    while(N--){
        scanf("%lld", &temp);
        v.push_back(temp);
    }
    return 0;
}
