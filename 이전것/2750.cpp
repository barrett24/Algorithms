//
//  2750.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t, num;
    vector<int> v;
    cin >> t;
    while(t--){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}
