//
//  2477-2.cpp
//  baek
//
//  Created by Sean on 2018. 3. 29..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int many;
vector<pair<int, int> > v;

int main()
{
    scanf("%d",&many);
    int x,y;
    for(int i=0;i<6;++i){
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    v.push_back(v[0]);
    
    int ans = 0, w=0, h=0;
    
    for(int i=0;i<6;++i){
        if(v[i].first==3 || v[i].first==4)
            h=max(h,v[i].second);
        else
            w=max(w,v[i].second);
        if((v[i].first==1 && v[i+1].first==3) ||//4가지 파인 경우
           (v[i].first==4 && v[i+1].first==1) ||
           (v[i].first==2 && v[i+1].first==4) ||
           (v[i].first==3 && v[i+1].first==2)){
            ans-=v[i].second*v[i+1].second;
        }
    }
    ans+=w*h;
    printf("%d",many*ans);
}
