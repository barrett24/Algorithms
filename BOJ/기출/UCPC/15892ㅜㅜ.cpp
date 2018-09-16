//
//  15892.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 7..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v[5001];
int cnt;
int n, m;
vector<int> k;

void BFS(int start){
    for(int i=0; i<v[start].size(); i++){
        
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
    }
    BFS(1);
    cout << cnt << endl;
    return 0;
}
