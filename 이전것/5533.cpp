//
//  5533.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[200][3], score[200];

int main(){
    int p;
    cin >> p;
    
    for(int i=1; i<=p; i++){
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    for(int i=1; i<=3; i++){
        for(int j=1; j<=p; j++){
            bool flage = true;
            for(int k=1; k<=p; k++){
                if(j!=k && arr[j][i] == arr[k][i])
                    flage = false;
            }
            if(flage) score[j] += arr[j][i];
        }
    }
    for(int i=1; i<=p; i++){
        cout << score[i] << endl;
    }
    return 0;
}
