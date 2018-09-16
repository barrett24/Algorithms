//
//  2631.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 6. 30..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//  LIS 알고리즘!!!!
//LIS 알고리즘은 다음과 같다.
//1. lis 배열에 아무 값이 없다면 조사 하는 배열(arr)의 첫번째 값을 넣는다.
//2. lis 배열의 가장 큰 값(가장 오른쪽에 있는 값) 보다 현재 보고 있는 arr[i] 값이 크다면 lis배열에 arr[i]값을 추가한다.
//3. 그 외에는 lower_bound(주어진 집합의 어떤 원소보다 작거나 같은 원소라는 뜻)을 이용하여 그 위치에 값을 넣어준다

#include <iostream>
#include <algorithm>
using namespace std;

int num[201];
int lis[201];

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &num[i]);
    lis[0] = num[0];
    int cnt=1;
    for(int i=0; i<N; i++){
        if(lis[cnt-1] < num[i]){//증가한 경우 추가
            lis[cnt] = num[i];
            cnt++;
        }
        else{
            *lower_bound(lis, lis+cnt, num[i]) = num[i];
            //정렬 유지한채 자신보다 작거나 같은 원소 대치
            //개수는 일치하지만 값이 변경됨, 값을 유지하려면 조치가 필요함
        }
    }
    printf("%d\n", N-cnt);
    return 0;
}
