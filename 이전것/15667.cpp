//
//  15667.cpp
//  baek
//
//  Created by Sean on 2018. 5. 4..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int N;
    int ans;
    scanf("%d", &N);
    N--;
    for(int i=1; i<N; i++){
        if(N == (i + i*i)){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
