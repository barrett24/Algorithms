//
//  2456.cpp
//  baek
//
//  Created by Sean on 2018. 5. 24..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

int n, r, c;
pair<int, int> p[3];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0, x; j < 3; j++){
            scanf("%d", &x);
            p[j].first += x;
            p[j].second += x*x;
        }
    
    if (p[1] > p[0])
        r = 1;
    else if (p[1] == p[0])
        c++;
    
    if (p[2] > p[r])
        r = 2, c = 0;
    else if (p[2] == p[r])
        c++;
    printf("%d %d", c ? 0 : r + 1, p[r].first);
    
    return 0;
}
