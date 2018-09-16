//
//  9507.cpp
//  baek
//
//  Created by Sean on 2018. 2. 18..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

long long arr[68] = {0,};

void func(){
    arr[0] = arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4; i<=67; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    }
}

int main(){
    int N, num;
    cin >> N;
    func();
    while(N--){
        cin >> num;
        cout << arr[num] << endl;
    }
    return 0;
}
