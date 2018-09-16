//
//  10872.cpp
//  baek
//
//  Created by Sean on 2017. 9. 5..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int fact(int n){
    if(n==0) return 1;
    else return n*fact(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}
