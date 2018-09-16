//
//  2667.cpp
//  baek
//
//  Created by Sean on 2018. 5. 4..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, k,chk[26][26], cnt[26*26];
char arr[26][26];

void dfs(int x, int y) {
    chk[x][y] = k;
    arr[x][y] = '0';
    cnt[k]++;
    
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] == '1')
                dfs(nx, ny);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == '1' && !chk[i][j]){
                ++k;
                dfs(i, j);
            }
    sort(cnt + 1, cnt + 1 + k);
    
    printf("%d\n", k);
    for (int i = 1; i <= k; i++)
        printf("%d\n", cnt[i]);
    
    return 0;
}
