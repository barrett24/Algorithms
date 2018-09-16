//
//  10819.cpp
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
    
    for(int i=0;i<n;++i)
        scanf("%d",&v[i]);
    
    sort(v.begin(),v.end());
    int ans = 0;
    
    do{
        int sum = 0;
        for(int i=0;i<n-1;++i){
            sum += abs(v[i]-v[i+1]);
        }
        ans = max(ans,sum);
        
    }while(next_permutation(v.begin(),v.end()));
    //조합함수를 이용한다
    printf("%d",ans);
}
