//
//  2477.cpp
//  baek
//
//  Created by Sean on 2018. 3. 29..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int many, wid=0, small=0, res = 0;
    int g=0, s=0;
    int sm = 0;
    int farm[14][3];
    
    scanf("%d", &many);
    
    for(int i=1; i<=6; i++){
        scanf("%d %d", &farm[i][1], &farm[i][2]);
        farm[i+6][1] = farm[i][1];
        farm[i+6][2] = farm[i][2];
    }
    
    for(int i=1; i<=6; i++){
        if(farm[i][1]==1 || farm[i][1]==2){
            g = max(g,farm[i][2]);
        }
        else if(farm[i][1]==3 || farm[i][1]==4){
            s = max(s, farm[i][2]);
        }
    }
    for(int i=1; i<=6; i++){
        if(farm[i][2]==g)
            sm = i;
    }
    wid = s * g;
    
    if((farm[sm][1]==1 && farm[sm+3][1]==4) || (farm[sm][1]==2 && farm[sm+3][1]==3))
        small = farm[sm+2][2]*farm[sm+3][2];
    else if((farm[sm][1]==1 && farm[sm+3][1]==3) || (farm[sm][1]==2 && farm[sm+3][1]==4) )
        small = farm[sm+3][2]*farm[sm+4][2];
    
    res = wid - small;
    
    printf("%d\n", res*many);
    
    return 0;
}
