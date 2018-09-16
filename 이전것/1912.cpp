
//
//  1912.cpp
//  baek
//
//  Created by Sean on 2017. 8. 30..
//  Copyright © 2017년 Sean. All rights reserved.
//
/*
#include <stdio.h>
int a[100000];
int d[100000];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        d[i] = a[i];
        if (i == 0) continue;
        if (d[i] < d[i-1] + a[i]) {
            d[i] = d[i-1] + a[i];
        }
    }
    int ans = d[0];
    for (int i=0; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    vector<int> d(n);
    for(int i=0; i<n; i++){
        d[i] = a[i];
        if(i==0) continue;
        if(d[i] < d[i-1] + a[i])
            d[i] = d[i-1] + a[i];
    }
    int ans = d[0];
    for(int i=1; i<n; i++){
        if(ans < d[i]){
            ans = d[i];
        }
    }
    cout << ans << endl;
    return 0;
}
