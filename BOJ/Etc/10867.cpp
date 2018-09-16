//
//  10867.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;
int num[2001];

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        int temp;
        scanf("%d", &temp);
        num[temp+1000] = 1;
    }
    for(int i=0; i<2001; i++){
        if(num[i] == 1) printf("%d ", i-1000);
    }
    printf("\n");
    return 0;
}
