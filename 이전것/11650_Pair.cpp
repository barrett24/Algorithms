//
//  11650.cpp
//  baek
//
//  Created by Sean on 2017. 9. 5..
//  Copyright © 2017년 Sean. All rights reserved.
// Pair : 2개의 성분을 가진 구조체
// C++11에서 가능
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a.begin(),a.end());
    for (int i=0; i<a.size(); i++) {
        printf("%d %d\n",a[i].first, a[i].second);
    }
    return 0;
}
