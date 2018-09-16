//
//  12813.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <stdio.h>
#define MAX 100000
using namespace std;

char s1[MAX+1], s2[MAX+1];

int main(){
    scanf("%s %s", s1, s2);
    for (int i=0; i<MAX; i++) {
        printf("%d", s1[i] == '1' && s2[i] == '1');
    }
    printf("\n");
    for (int i=0; i<MAX; i++) {
        printf("%d", s1[i] == '1' || s2[i] == '1');
    }
    printf("\n");
    for (int i=0; i<MAX; i++) {
        printf("%d", s1[i] != s2[i]);
    }
    printf("\n");
    for (int i=0; i<MAX; i++) {
        printf("%d", s1[i] != '1');
    }
    printf("\n");
    for (int i=0; i<MAX; i++) {
        printf("%d", s2[i] != '1');
    }
    printf("\n");
    return 0;
}
