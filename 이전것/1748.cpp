//
//  1748.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include<cstdio>
int n, r;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i *= 10) r += n - i + 1;
    printf("%d", r);
    return 0;
}
