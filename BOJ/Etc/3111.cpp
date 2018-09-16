//
//  3111.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 9. 12..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    string A, T;
    cin >> A;
    cin >> T;
    int As = (int)A.size();
    int Ts = (int)T.size();
    
    for(int i=0; i<Ts; i++)
        for(int j=0; j<As; j++){
            if(T[i+j] == A[j]){
                
            }
        }
    return 0;
}
