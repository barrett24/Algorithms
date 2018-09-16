//
//  2740.cpp
//  baek
//
//  Created by Sean on 2018. 2. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int a[101][101];
int b[101][101];
int c[101][101];
int n,m,k;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    cin >> m >> k;
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k; j++)
            cin >> b[i][j];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int p = 1; p <= m; p++)
                c[i][j] += a[i][p] * b[p][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            cout << c[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
