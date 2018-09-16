//
//  1967.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 3..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> v[10001];
bool visit[10001];
int dest;
int res;

void DFS(int node, int distance){
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
    for(int i=1; i<V; i++){
        scanf("%d %d %d", &from, &to, &dis);
        v[from].push_back(make_pair(to, dis));
        v[to].push_back(make_pair(from, dis));
    }
    DFS(1, 0);
    res = 0;
    memset(visit, false, sizeof(visit));
    DFS(dest, 0);
    printf("%d\n", res);
    return 0;
}
