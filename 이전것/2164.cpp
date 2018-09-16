//
//  2164.cpp
//  baek
//
//  Created by Sean on 2018. 4. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        q.push(i);
    
    int temp;
    
    while(q.size()!=1){
        q.pop();
        temp = q.front();
        q.push(temp);
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}
