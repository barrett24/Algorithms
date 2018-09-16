//
//  10451.cpp
//  baek
//
//  Created by Sean on 2017. 9. 16..
//  Copyright © 2017년 Sean. All rights reserved.
//  연결요소의 갯수 와 순열사이클의 갯수는 매우 비슷

#include <iostream>
using namespace std;
int a[1001];
bool c[1001];

void dfs(int x){
    if(c[x]) return;//이미 방문을 했다면 리턴
    c[x] = true;//다음정점은 1개이기 때문에
    dfs(a[x]);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            c[i] = false;
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(c[i] == false){
                dfs(i);
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
