//
//  1138.cpp
//  baek
//
//  Created by Sean on 2018. 2. 26..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>
using namespace std;

int n;
int key[12];
int v[12];
bool ok()
{
    for(int i=0;i<9;++i){
        int cnt = 0;
        for(int j=0;j<9;++j){
            if(i+1==v[j])break;
            if(i+1<v[j])++cnt;
        }
        if(cnt!=key[i])return false;
    }
    return true;
}
void f(int idx)
{
    if(idx == n){
        if(ok()){
            for(int i=0;i<n;++i)printf("%d ", v[i]);
            return;
        }
    }
    for(int i=0;i<n;++i){
        if(!v[i]){
            v[i] = idx+1;
            f(idx+1);
            v[i] = 0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&key[i]);
    f(0);
    return 0;
}
