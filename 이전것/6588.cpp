//
//  6588.cpp
//  baek
//
//  Created by Sean on 2017. 9. 4..
//  Copyright © 2017년 Sean. All rights reserved.
//  ****cin cout 쓰면 시간초과, printf scanf권장
// 백준에 제출한 코드 참고하기
#include <iostream>
#include <time.h>

using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn=0;
bool check[MAX+1];//true: 지워진것, false: 지워지지 않음(소수)

int main(){
    clock_t begin, end;
    begin = clock();
    
    check[0] = check[1] = true;
    for(int i = 2; i<=MAX; i++){
        if(check[i] == false){
            prime[pn++] = i;
            for(int j=i+i; j<=MAX; j+=i)
                check[j] = true;
        }
    }
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        for(int i = 1; i<pn; i++){
            if(check[n-prime[i]] == false){
                cout << n << "=" << prime[i] << "+" << n-prime[i] << endl;
                break;
            }
        }
    }
    end = clock();
    cout << ((end-begin)/CLOCKS_PER_SEC) << endl;
    return 0;
}
