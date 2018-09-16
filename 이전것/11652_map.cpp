//
//  11652_map.cpp
//  baek
//
//  Created by Sean on 2017. 9. 7..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    map<long long, int> d;
    while (n--) {
        long long x;
        scanf("%lld",&x);
        d[x] += 1;
    }
    int m = 0;
    long long ans = 0;
    for (auto &p : d) {
        if (p.second > m) {
            m = p.second;
            ans = p.first;
        } else if (p.second == m && p.first < ans) {
            ans = p.first;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
