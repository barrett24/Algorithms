//
//  1783.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 16..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <stdio.h>
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    if (n == 1) puts("1");
    else if (n == 2) {
        if (m <= 6) printf("%d", (m + 1) / 2);
        else puts("4");
    }
    else {
        if (m <= 4) printf("%d", m);
        else if (m == 5 || m == 6) puts("4");
        else printf("%d", m - 2);
    }
    return 0;
}
