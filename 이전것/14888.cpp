//
//  14888.cpp
//  baek
//
//  Created by Sean on 2018. 4. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int MIN = 1000000000;
int MAX = -1000000000;
int N, arr[12]={0,};
int add, sub, mul, divi;

void DFS(int cnt, int p, int mi, int mu, int di, int total){
    
    if(cnt==N){
        MAX = max(MAX,total);
        MIN = min(MIN,total);
        return;
    }
    if(p<add) DFS(cnt+1,p+1,mi,mu,di,total+arr[cnt+1]);
    if(mi<sub) DFS(cnt+1,p,mi+1,mu,di,total-arr[cnt+1]);
    if(mu<mul) DFS(cnt+1,p,mi,mu+1,di,total*arr[cnt+1]);
    if(di<divi) DFS(cnt+1,p,mi,mu,di+1,total/arr[cnt+1]);
}

int main(){
    //int plus, minus, mul, div;
    
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    cin >> add >> sub >> mul >> divi;
    
    DFS(1,0,0,0,0,arr[1]);
    
    cout << MAX << "\n" << MIN;
    return 0;
}
