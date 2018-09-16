//
//  1181.cpp
//  baek
//
//  Created by Sean on 2018. 2. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//  *************iterator c++******************

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const string &s1, const string &s2){
    if(s1.size() == s2.size()){
        return s1 < s2;
    }else{
        return s1.size() < s2.size();
    }
}

int main(){
    int t;
    string s;
    vector<string> v;
    cin >> t;
    while(t--){
        cin >> s;
        v.push_back(s);
    }
    vector<string>::iterator iter;
    vector<string>::iterator last_iter;
    
    sort(v.begin(), v.end(),comp);
    last_iter  = unique(v.begin(), v.end());
    
    for(iter = v.begin(); iter != last_iter; iter++){
        cout << *iter << endl;
    }
    return 0;
}
