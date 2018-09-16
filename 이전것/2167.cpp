//
//  2167.cpp
//  baek
//
//  Created by Sean on 2018. 1. 9..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int D[301][301] = { 0 };

int main(){
    int N, M, temp, t;
    int q,w,e,r;
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++){
            cin >> temp;
            D[i][j] = temp;
        }
    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> q >> w >> e >> r;
        int sum=0;
        for(int i=q; i<=e; i++)
            for(int j=w; j<=r; j++)
                sum += D[i][j];
        cout << sum << endl;
    }
    return 0;
}
