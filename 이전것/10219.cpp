//
//  10219.cpp
//  baek
//
//  Created by Sean on 2018. 6. 21..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    
    int T, H, W;
    char str[12];
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d %d\n", &H, &W);
        for(int i=0; i<H; i++){
            gets(str);
            reverse(str, str+W);
            puts(str);
        }
    }
    
    return 0;
}
