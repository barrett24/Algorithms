//
//  1927.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 4..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//
// <사용 함수>
//push(X) // 우선순위 큐에 새로운 값을 추가
//top() // 우선순위 큐의 루트 노드 리턴
//pop() // 우선순위 큐에서 루트 노드를 삭제
//size() // 우선순위 큐 내에 포함된 원소들의 수를 리턴
//empty() // 우선순위 큐가 empty이면 true를 리턴
//
//우선순위 큐 중 최댓값을 내놓는 것을 Max 힙, 최솟값을 내놓는 것을 Min 힙이라고 부릅니다.
//
//Max 힙을 사용할 때는
//1. priority_queue< int, vector<int> > q;
//2. priority_queue< int, vector<int>, less<int> > q;
//* less 의미가 Max 힙의 의미와 헷갈릴 수 있으니 주의하세요.
//3. 전달할 데이터가 2개 이상이면 다음과 같이 pair로 묶는다.
//priority_queue< pair<int,int> > pq;
//
//Min 힙을 사용할 때는
//1. priority_queue< int, vector<int>, greater<int> > q;
//2. 혹은 priority_queue< int, vector<int> > q;를 쓰고 push(-X) & -top() 같이 사용 가능.
//3. 전달할 데이터가 2개 이상이면 다음과 같이 pair로 묶는다.
//priority_queue< pair<int,int> > pq;를 쓰고 push(-X) & -top() 같이 사용 가능.
//
//pair로 묶었다면 .first 값을 1순위로 값을 뽑아내고 그다음 .second 값을 2순위로 값을 뽑아낸다.
//pair< int,pair<int,int> > 형태는 .first 1순위 .second.first 2순위 .second.second 3순위이다.

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;

int main() {
    scanf("%d", &n);
    int tmp;
    while (n--) {
        scanf("%d", &tmp);
        if (tmp) {
            pq.push(tmp);
        } else {
            if (pq.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        }
    return 0;
}
