//
//  10872.cpp
//  baek
//
//  Created by Sean on 2017. 9. 5..
//  Copyright © 2017년 Sean. All rights reserved.
//  소인수 분해

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=2; i*i <= n; i++){
        while(n%i == 0){
            printf("%d\n",i);
            n /= i;
        }
    }
    if(n > 1){
        printf("%d\n",n);
    }
    return 0;
}
