//
//  2564.cpp
//  baek
//
//  Created by Sean on 2018. 5. 23..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int r[101][2];

int main()
{
    ios::sync_with_stdio(false);
    int w, h, n, px, py, ans = 0;
    
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) cin >> r[i][0] >> r[i][1];
    cin >> px >> py;
    
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        if (r[i][0] == px) tmp += abs(r[i][1] - py);
        else if (r[i][0] + px == 3 || r[i][0] + px == 7)
        {
            if (px < 3)
            {
                tmp += h;
                tmp += min(py + r[i][1], 2 * w - py - r[i][1]);
            }
            else
            {
                tmp += w;
                tmp += min(py + r[i][1], 2 * h - py - r[i][1]);
            }
        }
        else
        {
            if (px == 1)
                tmp = (r[i][0] == 3) ? py + r[i][1] : w - py + r[i][1];
            else if (px == 2)
                tmp = (r[i][0] == 3) ? py + h - r[i][1] : w - py + h - r[i][1];
            else if(px==3)
                tmp = (r[i][0] == 1) ? py + r[i][1] : w - py + r[i][1];
            else
                tmp = (r[i][0] == 1) ? py + h - r[i][1] : w - py + h - r[i][1];
        }
        ans += tmp;
    }
    cout << ans << endl;
    
    return 0;
}
/*
 #include<cstdio>
 #include<algorithm>
 using namespace std;
 int n, r, c;
 pair<int, int> p[3];
 int main() {
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 for (int j = 0, x; j < 3; j++) scanf("%d", &x), p[j].first += x, p[j].second += x*x;
 if (p[1] > p[0]) r = 1;
 else if (p[1] == p[0]) c++;
 if (p[2] > p[r]) r = 2, c = 0;
 else if (p[2] == p[r]) c++;
 printf("%d %d", c ? 0 : r + 1, p[r].first);
 return 0;
 }

*/
