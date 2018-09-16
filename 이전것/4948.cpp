//
//  4948.cpp
//  baek
//
//  Created by Sean on 2018. 2. 25..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n, ans, arr[250000];
vector<int> v;

int main(){
    for(int i=2; i<250000; i++){//소수구하기 -> 소수를 벡터에
        if(arr[i] == 0)
            v.push_back(i);
        for(int j=i; j<250000; j+=i)//배수가 있으면 제외
            arr[j] = 1;
    }
    while(true){
        cin >> n;
        ans = 0;
        if(n==0)
            break;
        for(int i=0; i<v.size(); i++){
            if(v[i] > n && v[i]<=2*n)
                ans++;
            else if(v[i] > 2*n)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
