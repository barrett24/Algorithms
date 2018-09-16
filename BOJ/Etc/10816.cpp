//
//  10816.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

int n, m, x;

//이분 탐색
void bs(vector<P> &vv, int key) {
    int s = 0, e = vv.size() - 1;
    int mid;
    while (s <= e) {
        mid = (s + e) >> 1;
        if (vv[mid].first == key) {
            printf("%d ", vv[mid].second + 1);
            return;
        }
        else if (vv[mid].first < key) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    printf("0 ");
}

int main() {
    vector<int> v;
    scanf("%d", &n);
    v.resize(n);
    //벡터에 모든 입력받은 수 넣고 정렬하기
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    
    //중복되는 숫자 제거 및 빈도수 저장
    //first = num, second = frequency
    vector<P> vv;
    vv.push_back(P(v[0], 0));
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == vv[idx].first) {
            vv[idx].second++;
        }
        else {
            vv.push_back(P(v[i], 0));
            idx++;
        }
    }
    
    //이분탐색후 빈도수 출력
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &x);
        bs(vv, x);
    }
    printf("\n");
}
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int n;
//int m;
//vector<int> v;
//int cnt(int k)
//{
//    return (upper_bound(v.begin(),v.end(),k)-v.begin())-(lower_bound(v.begin(),v.end(),k)-v.begin());
//
//}
//int main()
//{
//    scanf("%d",&n);
//    v.resize(n);
//    for(int i=0;i<n;++i){
//        int x;
//        scanf("%d",&x);
//        v[i]= x;
//    }
//    sort(v.begin(),v.end());
//    scanf("%d",&m);
//    for(int i=0;i<m;++i){
//        int x;
//        scanf("%d",&x);
//        printf("%d ",cnt(x));
//    }
//
//}
