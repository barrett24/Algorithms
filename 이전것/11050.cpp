//
//  11050.cpp
//  baek
//
//  Created by Sean on 2018. 2. 20..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n,k,a=1,b=1;
    int ans = 0;
    cin >> n >> k;
    for(int i = n; i>=n-k+1; i--)
        a *= i;
    for(int i = k; i>=1; i--)
        b *= i;
    ans = a/b;
    cout << ans << endl;
    return 0;
}
