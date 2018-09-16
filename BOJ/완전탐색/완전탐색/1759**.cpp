//
//  1759.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 9. 11..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;

int main(){
    cin >> L >> C;
    vector<string> v;
    while(C--){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    int flag=1;
    do{
        if(flag == 1){
            for(int i=0; i<L; i++)
                cout << v[i];
            cout << endl;
            flag++;
        }
        if(flag == 2){
            flag--;
            continue;
        }
    }while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
