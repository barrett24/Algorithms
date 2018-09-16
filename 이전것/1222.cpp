//
//  1222.cpp
//  baek
//
//  Created by Sean on 2018. 3. 23..
//  Copyright © 2018년 Sean. All rights reserved.
//

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, temp;
    long long total=0, sum=0;
    int cnt=0;
    vector<int> v;
    scanf("%d",&N);
    
    for(int i=1; i<=N; i++){
        scanf("%d",&temp);
        v.push_back(temp);
    }
    temp = *max_element(v.begin(),v.begin()+v.size());
    for(int i=1; i<= temp; i++){
        for (vector<int>::iterator li = v.begin(); li != v.end(); li++){
            if((*li%i)==0){
                sum+=i;
                cnt++;
            }
        }
        if(cnt>=2 && sum>total) total = sum;
        sum = 0;
    }
    printf("%lld\n", total);
    return 0;
}*/
#include <iostream>
#include <algorithm>
using namespace std;//에라토스테네스의 체

const int MAX = 2000010;
int N, num[MAX];

int main(void) {
    int temp;
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; ++i) {
        scanf("%d", &temp);
        ++num[temp];
    }
    
    long long total = N;
    
    for(int i = 1; i <= 2000000; ++i) {
        long long sum = 0;
        for(int j = i; j <= 2000000; j += i)
            sum += num[j];
        if(sum > 1) total = max(total, sum * i);
    }
    
    printf("%lld\n", total);
    
    return 0;
    
}
