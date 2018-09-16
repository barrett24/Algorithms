
//
//  9613.cpp
//  baek
//
//  Created by Sean on 2017. 9. 2..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int t, n,a[1000001];
long long sum;
int GCD(int a, int b)
{
    if (b == 0) { return a; }
    return GCD(b,a%b);
}
int main() {
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                sum += GCD(a[i], a[j]);
            }
        }
        cout << sum << '\n';
    }
}
