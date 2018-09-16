//
//  2502.cpp
//  baek
//
//  Created by Sean on 2018. 5. 17..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int D, K;
int fibo[31];

int main(){
    scanf("%d %d", &D, &K);
    fibo[0] = 0, fibo[1] = 1;
    
    for(int i=2; i<31; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    int mul = 1;
    while(1){
        if((K - fibo[D-2]*mul) % fibo[D-1] == 0){
            printf("%d\n", mul);
            int ans = (K - fibo[D-2]*mul)/fibo[D-1];
            printf("%d\n",ans);
            break;
        }
        mul++;
    }
    return 0;
}
