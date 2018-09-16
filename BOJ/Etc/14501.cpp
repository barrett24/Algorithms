//
//  14501.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 6. 29..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int t[16];
int p[16];
int d[16];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (i + t[i] >= n + 1) {
            d[i] = max(d[i + 1], 0);
            continue;
        }
        d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
    }
    printf("%d\n", d[0]);
    return 0;
}
