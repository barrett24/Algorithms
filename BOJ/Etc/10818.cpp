//
//  10818.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int n;

int main()
{
    scanf("%d",&n);
    v.resize(n);
    
    for(int i=0;i<n;++i){
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
    printf("%d %d",v[0],v[v.size()-1]);
    
    return 0;
}
           
