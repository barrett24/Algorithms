//
//  2748.cpp
//  baek
//
//  Created by Sean on 2018. 2. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>

int main() {
    int num;
    long long int n[91];
    n[0] = 0;
    n[1] = 1;
    
    scanf("%d", &num);
    
    if (num >= 2) {
        for (int a = 2; a <= num; a++) {
            n[a] = n[a - 1] + n[a - 2];
        }
    }
    
    printf("%lld\n", n[num]);
    
}
