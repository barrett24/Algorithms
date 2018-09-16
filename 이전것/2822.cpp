//
//  2822.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int num[6] = {0,};
int score[9] = {0,};

int main(){
    int temp, sum=0;
    
    for(int i =1; i<=8; i++){
        cin >> temp;
        score[i] = temp;
    }
    for(int i =1; i<=5; i++){
        int max = -1;
        temp = 0;
        for(int j=1; j<=8; j++){
            if(score[j] > max)
            {
                max = score[j];
                temp = j;
            }
        }
        sum += max;
        score[temp] = -1;
        num[i] = temp;
    }
    sort(num+1, num + 6);
    cout << sum << endl;
    for(int i = 1; i<=5; i++)
        cout << num[i] << ' ';
    return 0;
}
