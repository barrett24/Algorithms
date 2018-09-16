//
//  1065.cpp
//  baek
//
//  Created by Sean on 2018. 2. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int N, cnt=0;
int x, y, z;

int main(){
    cin >> N;
    if(N<100){
        cnt = N;
        cout << cnt;
    }else{
        cnt = 99;
        for(int i =100; i<= N; i++){
            x = i/100;
            y = (i/10)%10;
            z = i%10;
            if((x-y) == (y-z)){
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}
