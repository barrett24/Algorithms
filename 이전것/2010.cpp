//
//  2010.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int N, M, sum=1;
    cin >> N;
    while(N--){
        cin >> M;
        sum += M-1;
    }
    cout << sum << endl;
    return 0;
}
