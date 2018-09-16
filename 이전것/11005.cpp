//
//  11005.cpp
//  baek
//
//  Created by Sean on 2017. 9. 2..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, b;
    cin >> n >> b;
    string ans =  "";
    while (n > 0) {
        int r = n % b;
        if (r < 10) {
            ans += (char)(r + '0');
        } else {
            ans += (char)(r - 10 + 'A');
        }
        n /= b;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
    return 0;
}
