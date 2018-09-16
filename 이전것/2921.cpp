//
//  2921.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int N, ans;
    cin >> N;
    ans = N*(N+1)*(N+2)/2;
    cout << ans << endl;
    return 0;
}
