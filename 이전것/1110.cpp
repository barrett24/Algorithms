//
//  1110.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int cnt = 0;
    int temp = N;
    
    do {
        cnt++;
        int A, B;
        
        B = temp % 10;
        A = temp / 10;
        int Sum = A + B;
        Sum %= 10;
        temp = (B * 10) + Sum;
    } while (N != temp);
    
    cout << cnt << endl;
    
    return 0;
}
