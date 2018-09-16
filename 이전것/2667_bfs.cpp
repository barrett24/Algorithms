//
//  2667.cpp
//  baek
//
//  Created by Sean on 2017. 9. 17..
//  Copyright © 2017년 Sean. All rights reserved.
//
/*
 한번 이동에서 모든 방향을 체크하기 위해서 아래오 같은 vector 를 이용하는 기법을 사용할 수 있다.
 대각선 까지 볼 경우에는 방향에 대한 vector 를 추가로 정의해서 처리하면 된다.
 
 int dx[] = {0,0,1,-1};
 int dy[] = {1,-1,0,0};
 */
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[30][30];//행과 열의 쌍으로 나타내어짐(2차원)
int group[30][30];
int dx[] = {0,0,1,-1};//2차원에서 이동하는 좌표값 인접한 4방향
int dy[] = {1,-1,0,0};
int n;
int ans[25*25];
void bfs(int x, int y, int cnt) {//각 단지를 탐색
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    group[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;//시작점 x행, y열
        y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];//상하좌우 이동
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (a[nx][ny] == 1 && group[nx][ny] == 0) {//칸의 값과 방문여부를 확인
                    q.push(make_pair(nx,ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && group[i][j] == 0) {
                bfs(i, j, ++cnt);
            }
        }
    }
    printf("%d\n",cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[group[i][j]]+=1;
        }
    }
    sort(ans+1, ans+cnt+1);
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
