//
//  5596.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int S=0, T=0;
    int i, m ,s ,e;

    cin >> i >> m >> s >> e;
    S = i+m+s+e;
    cin >> i >> m >> s >> e;
    T = i+m+s+e;
    
    if(S==T) cout << S << endl;
    else cout << max(S, T) << endl;
    return 0;
}
