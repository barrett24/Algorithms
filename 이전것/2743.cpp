//
//  2743.cpp
//  baek
//
//  Created by Sean on 2017. 8. 24..
//  Copyright © 2017년 Sean. All rights reserved.
//
/*
 #include <cstdio>
 #include <cstring>
 int main() {
 char a[111];
 scanf("%s",a);
 printf("%d\n",strlen(a));
 return 0;
 }
 
 #include <cstdio>
 char s[111];
 int main() {
 scanf("%s",s);
 int len = 0;
 for (int i=0; s[i]; i++) {
 len += 1;
 }
 printf("%d\n",len);
 }
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    cout << s.size() << '\n';
    return 0;
}
