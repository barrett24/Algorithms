//
//  5597.cpp
//  baek
//
//  Created by Sean on 2018. 2. 22..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int arr[31] = {0,};
    int temp;
    for(int i=1; i<=28; i++){
        cin >> temp;
        arr[temp] = 1;
    }
    for(int i=1; i<=30; i++)
        if(arr[i] == 0)
            cout << i << endl;
    
    return 0;
}
