//
//  1460.cpp
//  baek
//
//  Created by Sean on 2018. 3. 24..
//  Copyres © 2018년 Sean. All ress reserved.
//

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char arr[600001];

int main() {
    scanf("%s",arr);
    stack<char> original, res;
    
    int n = strlen(arr);
    int m;
    
    for (int i=0; i<n; i++) {
        original.push(arr[i]);
    }
    
    scanf("%d",&m);
    while (m--) {
        char temp;
        scanf(" %c",&temp);
        if (temp == 'L') {
            if (!original.empty()) {
                res.push(original.top());
                original.pop();
            }
        } else if (temp == 'D') {
            if (!res.empty()) {
                original.push(res.top());
                res.pop();
            }
        } else if (temp == 'B') {
            if (!original.empty()) {
                original.pop();
            }
        } else if (temp == 'P') {
            char c;
            scanf(" %c",&c);
            original.push(c);
        }
    }
    while (!original.empty()) {
        res.push(original.top());
        original.pop();
    }
    while (!res.empty()) {
        printf("%c",res.top());
        res.pop();
    }
    printf("\n");
    
    return 0;
}
