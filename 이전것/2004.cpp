//
//  2004.cpp
//  baek
//
//  Created by Sean on 2017. 9. 5..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long t =0, f=0;
    long long n,m;
    cin >> n >> m;
    for(long long i=2; i<=n; i*=2){
        t += n/i;
    }
    for(long long i=2; i<=n-m; i*=2){
        t -= (n-m)/i;
    }
    for(long long i=2; i<=m; i*=2){
        t -= m/i;
    }
    for(long long i=5; i<=n; i*=5){
        f += n/i;
    }
    for(long long i=5; i<=n-m; i*=5){
        f -= (n-m)/i;
    }
    for(long long i=5; i<=m; i*=5){
        f -= m/i;
    }
    cout << min(t,f) << endl;
    return 0;
}
