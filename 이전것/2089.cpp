//
//  2092.cpp
//  baek
//
//  Created by Sean on 2017. 9. 2..
//  Copyright © 2017년 Sean. All rights reserved.
// -2
#include <iostream>
using namespace std;

void go(int n){
    if(n==0) return;
    
    if(n%2 == 0){
        go(-(n/2));
        cout << '0';
    }else{
        if(n>2){
            go(-(n/2));
        }else{
            go((-n+1)/2);
        }
        cout << '1';
    }
}
int main(){
    int n;
    cin >> n;
    if(n==0){
        cout << '0' << endl;
    }else go(n);
    
    return 0;
}
