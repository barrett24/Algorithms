//
//  2293.cpp
//  baek
//
//  Created by Sean on 2018. 1. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int n, k, cnt;
int N[101] = {0,};
int K[10001] = {0,};

int main(){
    cin >> n >> k;
    for(int i = 1; i<=n; i++)
        cin >> N[i];
    K[0] = 1;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=k; j++)
        {
            if(j>=N[i])
                K[j] += K[j - N[i]];
        }
    cout << K[k] << endl;
    return 0;
}
