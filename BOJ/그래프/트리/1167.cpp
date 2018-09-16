//
//  1167.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 3..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> v[100002];
bool visit[100002];
int dest;
long long res;

void DFS(int node, long long distance){
    visit[node] = true;
    if(distance > res){
        res = distance;
        dest = node;
    }
    for(int i=0; i<v[node].size(); i++){
        if(visit[v[node][i].first] == false)
            DFS(v[node][i].first, v[node][i].second + distance);
    }
}

int main(){
    int V;
    scanf("%d", &V);
    int from, to, dis;
    for(int i=0; i<V; i++){
        scanf("%d", &from);
        while(1){
            scanf("%d", &to);
            if(to == -1) break;
            scanf("%d", &dis);
            v[from].push_back(make_pair(to, dis));
        }
    }
    DFS(1, 0);
    res = 0;
    memset(visit, false, sizeof(visit));
    DFS(dest, 0);
    printf("%lld\n", res);
    return 0;
}
