//
//  2839.cpp
//  baek
//
//  Created by Sean on 2018. 3. 23..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>

int main() {
    
    int N;
    int cnt = 0;
    scanf("%d", &N);
    
    while (N > 0) {
        if (N % 5 == 0) {
            cnt += N / 5;
            break;
        }
        else {
            N -= 3;
            cnt++;
        }
    }
    if (N < 0) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", cnt);
    
    
    return 0;
}
