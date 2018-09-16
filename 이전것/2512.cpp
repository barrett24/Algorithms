//
//  2512.cpp
//  baek
//
//  Created by Sean on 2018. 5. 10..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

long long mon[10001];
long long N, total;

int main(){
    scanf("%lld", &N);
    
    for(int i=0; i<N; i++)
        scanf("%lld", &mon[i]);
    
    scanf("%lld", &total);
    
    long long left = total/N;
    long long right = max_element(*mon, *mon+N);
    
    while(left <= right){
        long long mid = (left + right)/2;
        long long temp = total;
        
        for(int i = 0; i < N; i++){
            if(mid >= mon[i])
                temp -= mon[i];
            else temp -= mid;
        }
        if(temp >= 0)
            left = mid + 1;
        else right = mid - 1;
    }
    printf("%lld\n", right);
    
    return 0;
}
