//
//  10971.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 8. 13..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, Max = 2147483647;
int city[20][20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> city[i][j];
    vector<int> v(N-1);
    //v.resize(N-1);
    for(int i=1; i<N; i++)
        v[i-1] = i;
    
    do{
        int sum = 0;
        bool check = true;
        for(int i=0; i<N-2; i++){
            if(city[v[i]][v[i+1]] == 0)
                check = false;
            else
                sum += city[v[i]][v[i+1]];
        }
        if(check == true && city[0][v[0]] != 0 && city[v[N-2]][0] != 0){
            sum += city[0][v[0]] + city[v[N-2]][0];
            Max = min(Max, sum);
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << Max << endl;
    return 0;
}
