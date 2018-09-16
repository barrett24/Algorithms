//
//  1076.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int i, j;
long long sum;
string a, b, c, s[] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white" };

int main() {
    cin >> a >> b >> c;
    
    for (i = 0; i < 10; i++) {
        if (a == s[i]) sum += i * 10;
        if (b == s[i]) sum += i;
    }
    for (i = 0; i < 10; i++) if (c == s[i])
        for (j = 0; j < i; j++) sum *= 10;
    
    cout << sum;
    
    return 0;
}
