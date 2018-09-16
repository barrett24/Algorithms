//
//  2309.cpp
//  baek
//
//  Created by Sean on 2018. 5. 4..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> nan;
    vector<int> ans;
    
    for(int i=0; i<9; i++){
        int temp;
        scanf("%d", &temp);
        nan.push_back(temp);
    }
    bool complete = false;
    
    for(int i=0; i<9 && complete == false; i++)
        for(int j=i+1; j<9 && complete == false; j++){
            int sum = 0;
            ans.clear();
            for(int k=0; k<9; k++){
                if(k!=i && k!=j){
                    ans.push_back(nan[k]);
                    sum += nan[k];
                }
            }
            if(sum==100)
                complete = true;
        }
    
    sort(ans.begin(), ans.end());
    for(int i=0; i<7; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}
