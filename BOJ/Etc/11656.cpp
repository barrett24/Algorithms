//
//  11656.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 11..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> v;
    string in;
    cin >> in;
    //v.resize(in.size());
    int l = in.size();
    for(int i=0; i<l; i++){
        v.push_back(in);
        in.erase(0,1);
    }
    sort(v.begin(),v.begin()+l);
    for(int i=0; i<l; i++){
        cout << v[i] << "\n";
    }
    return 0;
}
