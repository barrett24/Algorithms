//
//  10039.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <stdio.h>
int main(){
    
    int score[5] = {0, }, i, sum = 0;
    
    
    for(i = 0; i < 5; i++){
        
        scanf("%d", &score[i]);
        
        if(score[i] <= 40){
            
            score[i] = 40;
        }
        
        sum += score[i];
    }
    
    printf("%d", sum/5);
    return 0;
}
