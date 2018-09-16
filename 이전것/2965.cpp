//
//  2965.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C;
    int ans;
    cin >> A >> B >> C;
    ans = max(abs(B-A), abs(C-B)) - 1;
    cout << ans << endl;
    return 0;
}
