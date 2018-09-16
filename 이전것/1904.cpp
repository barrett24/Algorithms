//
//  1904.cpp
//  baek
//
//  Created by Sean on 2018. 2. 6..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int arr[1000001] = { 0, };
int D[1000001] = { 0, };

int main(){
    
    cin >> n;
    
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= n; i++){
        D[i] = (D[i - 1] + D[i - 2])%15746;
    }
    cout << D[n] << endl;
    
    
    return 0;
}
