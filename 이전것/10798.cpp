//
//  10798.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <stdio.h>
#define MAX 15

char arr[5][15];
int main(){
    for(int i=0; i<5; ++i)
        scanf("%s",arr[i]);
    
    for(int j=0; j<MAX; ++j)
        for(int i=0; i<5; ++i){
            if(arr[i][j] == NULL) continue;
            else printf("%c", arr[i][j]);
        }
    return 0;
}
