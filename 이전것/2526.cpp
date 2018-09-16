//
//  2526.cpp
//  baek
//
//  Created by Sean on 2018. 5. 17..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int N, P, cnt;
int arr[97];

int main(){
    scanf("%d %d", &N, &P);
    int temp = N % P;
    int i;
    for(i = temp; !arr[i]; i = i*N%P){
        arr[i] = ++cnt;
    }
    temp = cnt - arr[i] +1;
    printf("%d", temp);
    
    return 0;
}
