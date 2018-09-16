//
//  1541.cpp
//  baek
//
//  Created by Sean on 2018. 2. 26..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
char cal[51] = {0,};
int ret=0, n=0, i=0, flag=0;

int main(){
    scanf("%s", cal);
    while(cal[i] != 0){
        if(cal[i] >= '0' && cal[i] <= '9'){
            n *= 10;
            n += cal[i]-'0';
        }
        else{
            if(flag==0) ret += n;
            else ret -= n;
            if(cal[i]=='-' && flag==0) flag=1;
            n=0;
        }
        i++;
    }
    if(flag==0) ret += n;
    else if(flag==1) ret -= n;
    printf("%d", ret);
    return 0;
}
