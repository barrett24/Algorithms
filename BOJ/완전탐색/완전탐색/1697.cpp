//
//  1697.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 14..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
bool vis[100001];
int cnt;

void BFS(int N, int K){
    if(N == K){ //시작채널과 목표채널이 같을경우 0출력
        printf("0\n");
    }else{
        queue<int> q;
        q.push(N);//큐에 시작채널을 삽입
        vis[N] = true;//시작채널을 방문했음을 체크
        
        while(!q.empty()){
            int size = (int)q.size();

            for(int i=0; i < size; i++){
                int now = q.front();
                q.pop();
                
                if(now == K){//목표채널에 도달했을 경우
                    printf("%d\n", cnt);
                    break;
                }
                if(now-1 >= 0 && vis[now-1] == false){//위치-1값에 방문하지 않았다면
                    q.push(now-1);
                    vis[now-1] = true;
                }
                if(now+1 <= 100001 && vis[now+1] == false){//위치+1값에 방문하지 않았다면
                    q.push(now+1);
                    vis[now+1] = true;
                }
                if(now*2 <= 100001 && vis[now*2] == false){//위치*2값에 방문하지 않았다면
                    q.push(now*2);
                    vis[now*2] = true;
                }
            }
            cnt++;//채널 변경 수 증가
        }
    }
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    BFS(N, K);
    return 0;
}


