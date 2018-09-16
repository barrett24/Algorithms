//
//  1010.cpp
//  baek
//
//  Created by Sean on 2018. 1. 9..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int D[31][31] = {0};

int main(){
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
        int N, M;
        cin >> N >> M;
    
        for(int i=1; i<=M; i++)
            D[1][i] = i;
    
        for(int i=2; i<=N; i++)
            for(int j=i; j<=M; j++)
                D[i][j] = D[i][j-1] + D[i-1][j-1];
        cout << D[N][M] << endl;
    }
    return 0;
}
