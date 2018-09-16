//
//  11052.cpp
//  baek
//
//  Created by Sean on 2017. 8. 25..
//  Copyright © 2017년 Sean. All rights reserved.
//
//d[n] = n개팔아서 얻는 최대 수익, p[i] = i개팔았을때
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    vector<int> d(n+1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            d[i] = max(d[i], d[i-j]+a[j]);
    }
    cout << d[n] << endl;
    return 0;
}
