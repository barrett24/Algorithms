//
//  1654.cpp
//  baek
//
//  Created by Sean on 2018. 5. 16..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long K, N;
long long arr[10001];

int main() {
    scanf("%lld%lld", &K, &N);
    for (int i = 0; i < K; i++)
        scanf("%lld", &arr[i]);
    
    long long left, right;
    left = 0;
    right = 10000000001;
    
    while (left < right) {
        long long mid, sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < K; i++)
            sum += arr[i] / mid;
        if (sum >= N)
            left = mid + 1;
        else
            right = mid;
    }
    printf("%lld\n", left - 1);
    
    return 0;
}
