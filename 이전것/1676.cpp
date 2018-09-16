//
//  1676.cpp
//  baek
//
//  Created by Sean on 2017. 9. 5..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n, ans=0;
    cin >> n;
    for(int i=5; i<=n; i*=5){
        ans = n/i;
    }
    cout << ans << endl;
    return 0;
}
