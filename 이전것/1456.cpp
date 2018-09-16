//
//  1456.cpp
//  baek
//
//  Created by Sean on 2018. 5. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>

int main(){
    long long min, max;
    int count = 0;
    scanf("%lld%lld", &min, &max);
    bool *isPrimeNumber = new bool[(int)1e+7 + 1];
    int *primeNumber = new int[(int)1e+7 + 1];
    int cnt = 0;
    for(long long i = 2; i * i <= max ; i++){
        if(!isPrimeNumber[i]){
            for(long long j = i * 2; j * j <= max; j += i) isPrimeNumber[j] = true;
            primeNumber[cnt++] = i;
        }
    }
    
    for(int i = 0; i < cnt; i++){
        long long n = primeNumber[i];
        while(primeNumber[i] <= max / n){
            if(primeNumber[i] * n >= min) count++;
            n *= primeNumber[i];
        }
    }
    
    printf("%d", count);
    
    return 0;
}

