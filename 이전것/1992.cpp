//
//  1992.cpp
//  baek
//
//  Created by Sean on 2018. 2. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>

int n;
int map[65][65];

void solve(int y, int x, int length)
{
    int i, j, k;
    int flag = map[y][x];
    int dy[4] = { 0, 0, 1, 1 };
    int dx[4] = { 0, 1, 0, 1 };
    
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (flag != map[y + i][x + j]) {
                printf("(");
                for (k = 0; k < 4; k++) {
                    solve(y + dy[k] * length / 2, x + dx[k] * length / 2, length / 2);
                }
                printf(")");
                return;
            }
        }
    }
    
    printf("%d", flag);
}

int main()
{
    int i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    solve(0, 0, n);
    printf("\n");
    
    return 0;
}
