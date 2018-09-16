//
//  11651_reverse.cpp
//  baek
//
//  Created by Sean on 2017. 9. 7..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i].second, &a[i].first);
    }
    sort(a.begin(), a.end());
    for(auto &p : a){
        printf("%d %d\n", p.second, p.first);
    }
    return 0;
}
