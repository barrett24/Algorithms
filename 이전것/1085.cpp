//
//  1085.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x, y, w, h, ans;
    cin >> x >> y >> w >> h;
    
    int x1 = abs(w-x);
    int y1 = abs(h-y);
    ans = min(min(x-0, x1), min(y-0, y1));
    cout << ans << endl;
    return 0;
}
