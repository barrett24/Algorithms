//
//  1991.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 1..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <stdio.h>
char left[26];
char right[26];
void pre_travel(int idx){
    printf("%c", (char)idx+'A');
    if(left[idx] != '.')
        pre_travel(left[idx]-'A');
    if(right[idx] != '.')
        pre_travel(right[idx]-'A');
}

void in_travel(int idx){
    if(left[idx] != '.')
        in_travel(left[idx]-'A');
    printf("%c", (char)idx+'A');
    if(right[idx] != '.')
        in_travel(right[idx]-'A');
}
void post_travel(int idx){
    if(left[idx] != '.')
        post_travel(left[idx]-'A');
    if(right[idx] != '.')
        post_travel(right[idx]-'A');
    printf("%c", (char)idx+'A');
    
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char t1, t2, t3;
        scanf(" %c %c %c", &t1, &t2, &t3);
        left[t1-'A'] = t2;
        right[t1-'A'] = t3;
    }
    pre_travel(0);
    printf("\n");
    in_travel(0);
    printf("\n");
    post_travel(0);
    printf("\n");
}
