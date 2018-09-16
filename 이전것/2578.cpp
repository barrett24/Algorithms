//
//  2578.cpp
//  baek
//
//  Created by Sean on 2018. 5. 17..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int input[6][6];

int bingo(){
    int cnt = 0;
    for(int i=1; i<6; i++){
        if(input[i][1] == 0 && input[i][2] == 0 && input[i][3] == 0 && input[i][4] == 0 && input[i][5] == 0)
            cnt++;
    }
        
    for(int j=1; j<6; j++){
        if(input[1][j] == 0 && input[2][j] == 0 && input[3][j] == 0 && input[4][j] == 0 && input[5][j] == 0)
            cnt++;
    }
    if(input[1][1] == 0 && input[2][2] == 0 && input[3][3] == 0 && input[4][4] == 0 && input[5][5] == 0)
        cnt++;
    if(input[5][1] == 0 && input[4][2] == 0 && input[3][3] == 0 && input[2][4] == 0 && input[1][5] == 0)
        cnt++;
    return cnt;
}

int main(){
    for(int i=1; i<6; i++)
        for(int j=1; j<6; j++){
            scanf("%d", &input[i][j]);
        }
    int N = 25;
    while(N--){
        int temp;
        scanf("%d", &temp);
        for(int i=1; i<6; i++)
            for(int j=1; j<6; j++){
                if(input[i][j] == temp){
                    input[i][j] = 0;
                    if(bingo() >= 3){
                        printf("%d\n", 25-N);
                        return 0;
                    }
                }
            }
    }
    return 0;
}
