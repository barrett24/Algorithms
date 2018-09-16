//
//  11053.cpp
//  baek
//
//  Created by Sean on 2017. 8. 29..
//  Copyright © 2017년 Sean. All rights reserved.
//
/*
 #include <stdio.h>
 int a[1000];
 int d[1000];
 int main() {
 int n;
 scanf("%d",&n);
 for (int i=0; i<n; i++) {
 scanf("%d",&a[i]);
 }
 for (int i=0; i<n; i++) {
 d[i] = 1;
 for (int j=0; j<i; j++) {
 if (a[j] < a[i] && d[i] < d[j]+1) {
 d[i] = d[j]+1;
 }
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
    for(int i=0; i<n; i++) {
        d[i] = 1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i] && d[j]+1 > d[i])
                d[i] = d[j]+1;
        }
    }
    cout << *max_element(d.begin(), d.end()) << endl;
    return 0;
}

