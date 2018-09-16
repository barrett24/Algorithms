//
//  1107.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 12..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int remote[10] = { 1 }; // 고장난거

int possible(int n) {      //
    if (n == 0) {
        if (remote[0] != -1)return 1;   // 고장 안났다면
        else return -1;               // 고장 났다면
    }
    int len = 0;
    while (n > 0)
    {
        if (remote[n % 10] == -1)
            return -1;
        else{
            n /= 10;
            
            len++;
        }
    }
    return len;
}

int main() {
    int N = 0;
    int M = 0;
    scanf("%d", &N);
    scanf("%d", &M);
    
    int tp = 0;
    
    for (int i = 0; i<M; i++) {
        scanf("%d", &tp);
        remote[tp] = -1;      // 고장난건 -1
    }
    
    int cur = fabs(100 - N);   // 현재에서 목표까지
    
    int res = 0, minVal = 1000000, press = 0;
    
    for (int i = 0; i<1000000; i++) {
        
        press = possible(i);
        
        if (press > 0) {
            res = fabs(N - i) + press;
            if (res < minVal) {
                minVal = res;
            }
        }
    }
    
    int ret = min(minVal, cur);
    
    printf("%d\n", ret);
    
    return 0;
}
