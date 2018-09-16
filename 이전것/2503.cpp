//
//  2503.cpp
//  baek
//
//  Created by Sean on 2018. 5. 9..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX_SIZE 100
#define MAX_NUM 988
typedef pair<int, int> P;

int question[MAX_SIZE];
P answer[MAX_SIZE];
bool flag[MAX_NUM];

int strike(int a, int b) {//a, b 두 수가 몇 스크라이크 인지 출력 (같은 위치에 같은 숫자가 있으면 strike)
    
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (a / (int)pow(10, i) % 10 == b / (int)pow(10,i) % 10) {
            cnt++;
        }
    }
    return cnt;
}

int ball(int a, int b) {//a, b 두 수가 몇 볼인지 출력(다른위치에 같은 숫자가 있으면 ball)
    
    int cnt = 0;
    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;//이 코드가 없으면 strike도 포함됨
            if (a / (int)pow(10, i) % 10 == b / (int)pow(10, j) % 10){
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    
    for (int i = 123; i < MAX_NUM; i++)
        flag[i] = true;
    
    for (int i = 123; i < MAX_NUM; i++) {
        if (i / 100 == i % 100 / 10 || i / 100 == i % 100 % 10 || i % 100 / 10 == i % 100 % 10
            || i/100 == 0 || i%100/10 == 0 || i%100%10 == 0) {//각 자리수가 같거나 0 인경우
            flag[i] = false;
        }
    }
    
    for (int i = 0; i < N; i++) {
        cin >> question[i] >> answer[i].first >> answer[i].second;
        for (int j = 123; j < MAX_NUM; j++) {
            if (flag[j]) {
                if (answer[i].first != strike(question[i], j) ||
                    answer[i].second != ball(question[i], j)) {
                    flag[j] = false;
                }
            }
        }
    }
    
    int cnt = 0;
    for (int i = 123; i < MAX_NUM; i++)
        if (flag[i])
            cnt++;
    
    cout << cnt;
    
    return 0;
}
