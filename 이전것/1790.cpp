//
//  1790.cpp
//  baek
//
//  Created by Sean on 2018. 3. 23..
//  Copyright © 2018년 Sean. All rights reserved.
//
/*
 #include <cstdio>
 int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1, p = 1; ; ++i, p *= 10) {
        if (k > p * 9 * i) {
            k -= p * 9 * i;
        } else {
            --k;
        int t = p + k / i;
        if (t > n) {
            printf("-1");
            return 0;
        }
        for (int j = i - k % i; j > 1; --j, t /= 10);
            printf("%d", t % 10);
        return 0;
        }
    }
    return 0;
 } */
#include <iostream>
using namespace std;

int main(){
    int N, K;
    long long p = 1, cnt = 1;
    scanf("%d %d", &N, &K);
    K--;
    
    bool lessDigits = false;
    
    while(N >= p*10){
        if(K < p*9*cnt){
            lessDigits = true;
            break;
        }
        K -= p*9*cnt;
        cnt++;
        p *= 10;
    }
    
    long long q = K/cnt + p;
    if(!lessDigits && q > N%(p*10))
        printf("-1");
    else{
        int r = K%cnt;
        for(int i=0; i<cnt-r-1; i++)
            q /= 10;
        printf("%lld\n", q%10);
    }
}
