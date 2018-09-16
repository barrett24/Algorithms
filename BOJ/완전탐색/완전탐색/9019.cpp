//
//  9019.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 9. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int t, a, b;
bool visited[10000];


void BFS() {
    visited[a] = true;
    
    queue<pair<int, string>> q;
    q.push({a, ""});
    
    int tmp;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        
        if (x.first == b) {
            printf("%s\n", x.second.c_str());
            return;
        }
        
        tmp = (x.first * 2) % 10000;
        if (!visited[tmp]) {
            q.push({tmp, x.second + 'D'});
            visited[tmp] = true;
        }// D
        
        tmp = (x.first - 1 + 10000) % 10000;
        if (!visited[tmp]) {
            q.push({tmp, x.second + 'S'});
            visited[tmp] = true;
        }// S
        
        tmp = (x.first * 10) % 10000 + x.first / 1000;
        if (!visited[tmp]) {
            q.push({tmp, x.second + 'L'});
            visited[tmp] = true;
        }// L
        
        tmp = x.first / 10 + (x.first % 10) * 1000;
        if (!visited[tmp]) {
            q.push({tmp, x.second + 'R'});
            visited[tmp] = true;
        }// R
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        memset(visited, false, sizeof(visited));
        BFS();
    }
    return 0;
}
