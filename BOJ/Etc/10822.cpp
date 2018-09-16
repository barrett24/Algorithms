//
//  10821.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    vector<string> v;
    int sum=0;
    cin >> s;
    string num;
    for(string::iterator it = s.begin(); it!=s.end(); it++){
        if(*it != ','|| *it != '\0') num += *it;
        if(*it == ',' || *it == '\0'){
            v.push_back(num);
            num.erase();
        }
    }
    vector<string>::iterator iter;
    for(iter = v.begin(); iter!=v.end(); iter++){
        sum += stoi(*iter);
    }
    sum += stoi(num);
    cout << sum;
    return 0;
}
