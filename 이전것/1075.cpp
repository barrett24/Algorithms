//
//  1075.cpp
//  baek
//
//  Created by Sean on 2018. 3. 30..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, f;
    
    scanf("%d %d", &n, &f);
    
    n = (n/100)*100;
    
    while (true) {
        if (n % f == 0)
            break;
        ++n;
    }
    
    n %= 100;
    
    if (n < 10) {
        printf("0");
    }
    
    printf("%d", n);
    return 0;
}
