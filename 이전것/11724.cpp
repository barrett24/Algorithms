//
//  11724.cpp
//  baek
//
//  Created by Sean on 2017. 9. 16..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int node){//같은 소스
    check[node] = true;//체크해주기
    for(int i=0; i<a[node].size(); i++){//다음정점을 찾는 과정
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int components = 0;
    for(int i=1; i<=n; i++){//모든 점
        if(check[i] == false){//방문하지 않았으면
            dfs(i);
            components += 1;//연결요소의 개수 = dfs를 몇번 실행했는가
        }
    }
    printf("%d\n", components);
    return 0;
}
