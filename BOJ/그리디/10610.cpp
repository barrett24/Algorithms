//
//  10610.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 16..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main () {
    char stringNumber[100002];
    int number[10];
    int sum = 0;
    scanf("%s", stringNumber);
    int size = strlen(stringNumber);
    
    for (int i = 0; i < size; i++) {
        int n = stringNumber[i] - '0';
        number[n]++;
        sum += n;
    }
    
    if (sum % 3 == 0 && number[0]) {
        for (int i = 9; i >= 0; i--)
            while (number[i]) {
                printf("%d", i);
                number[i]--;
            }
    } else printf("-1");
    
    return 0;
}

