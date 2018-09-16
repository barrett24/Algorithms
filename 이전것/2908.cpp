
//
//  2908.cpp
//  baek
//
//  Created by Sean on 2018. 5. 24..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    int RA, RB;
    RA = (A%10)*100 + ((A%100)/10)*10 + (A/100);
    RB = (B%10)*100 + ((B%100)/10)*10 + (B/100);
    int MA = max(RA, RB);
    printf("%d", MA);
    return 0;
}
