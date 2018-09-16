//
//  test.cpp
//  baek
//
//  Created by Sean on 2017. 9. 17..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int d(int n){
    if(n==10000)
        return n+n/10000+n/1000%10+n/100%10+n/10%10;
    else{
        if(n<1000){
            if(n<100){
                if(n<10)
                    return n+n;
                else
                    return n+n%10+(n/10);
            }
            else
                return n+n/100+(n/10%10)+n%10;
        }
        else
            return n+n/1000+(n/100%10)+(n/10%10)+n%10;
    }
}
bool selfnumber(int n){
    bool isSelf=true;
    for(int i=0;i<n;i++)
        if(d(i)==n){
            isSelf=false;
            break;
        }
    return isSelf;	
}
int main(){
    for(int i=1;i<=10000;i++)
        if(selfnumber(i)==1)
            cout<<i<<endl;
}
