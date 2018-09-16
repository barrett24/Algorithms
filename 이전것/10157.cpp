//
//  10157.cpp
//  baek
//
//  Created by Sean on 2018. 5. 23..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m, c, a[1002][1002];

int main() {
    scanf("%d %d %d", &n, &m, &c);
    
    for (int i = 0; i <= 1001; i++)
        a[i][0] = a[0][i] = a[m + 1][i] = a[i][n + 1] = 1;
    
    int x = 0, y = 1, d = 0;
    
    for (int i = 1; i <= n*m; i++) {
        x += dx[d];
        y += dy[d];
        a[x][y] = 1;
        
        if (a[x + dx[d]][y + dy[d]])
            d = (d + 1) % 4;
        if (i == c) {
            printf("%d %d", y, x);
            return 0;
        }
    }
    
    printf("0");
    
    return 0;
}
