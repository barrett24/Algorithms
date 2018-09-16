//
//  1159.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int a[26], n,p;
string k;
int main() {
    cin >> n;
    while (n--)
    {
        cin >> k;
        a[k[0]-'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (a[i] >= 5)
        {
            printf("%c", i + 'a');
            p = 1;
        }
    if (p == 0)
        cout << "PREDAJA" << '\n';
}
