//
//  1963.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 9. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int visit[100000];
int T, a, b, ret;
bool flag;

bool prime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i*i <= n; i++)
        if (n%i == 0) return false;
    return true;
}

void BFS() {
    int size;
    
    while (!q.empty()) {
        size = (int)q.size();
        ret++;
        for (int i = 0; i < size; i++) {
            int now = q.front();
            q.pop();
            
            if (now == b) {
                flag = true;
                return;
            }
            
            int tmp_now = now;
            tmp_now = now - (now % 10);
            for (int i = 0; i < 10; i++) { //1
                if (prime(tmp_now + i) && visit[tmp_now + i] == 0) {
                    q.push(tmp_now + i);
                    visit[tmp_now + i] = 1;
                }
            }
            tmp_now = now - ((now % 100) / 10) * 10;
            for (int i = 0; i < 10; i++) {//10
                if (prime(tmp_now + (i * 10)) && visit[tmp_now + (i * 10)] == 0) {
                    q.push(tmp_now + (i * 10));
                    visit[tmp_now + (i * 10)] = 1;
                }
            }
            tmp_now = now - ((now % 1000) / 100) * 100;
            for (int i = 0; i < 10; i++) {//100
                
                if (prime(tmp_now + i * 100) && visit[tmp_now + i * 100] == 0) {
                    q.push(tmp_now + i * 100);
                    visit[tmp_now + i * 100] = 1;
                }
            }
            tmp_now = now - (now / 1000) * 1000;
            for (int i = 1; i < 10; i++) {//1000
                
                if (prime(tmp_now + (i * 1000)) && visit[tmp_now + (i * 1000)] == 0) {
                    q.push(tmp_now + (i * 1000));
                    visit[tmp_now + (i * 1000)] = 1;
                }
            }
        }
    }
}

int main(void) {
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        ret = -1;
        flag = false;
        for (int i = 1001; i < 100000; i++) visit[i] = 0;
        while (!q.empty()) q.pop();
        
        visit[a] = 1;
        q.push(a);
        BFS();
        
        if (flag)
            printf("%d\n", ret);
        else
            printf("Impossible\n");
    }
    return 0;
}
