//
//  5576.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int W[10], K[10], w=0, k=0;
    for(int i=1; i<=10; i++)
        cin >> W[i];
    for(int i=1; i<=10; i++)
        cin >> K[i];
    sort(W+1, W+11);
    sort(K+1, K+11);
    for(int i=8; i<=10; i++){
        w += W[i];
        k += K[i];
    }
    cout<< w << ' ' << k << endl;
    return 0;
}
