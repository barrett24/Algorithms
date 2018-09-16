//
//  2251.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 9. 10..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int A, B, C;
bool cache[201][201][201];

vector<int> BFS(void)
{
    //queue < pair<pair<int, int>, int>> q;
    queue <tuple<int, int, int>> q;
    //q.push(make_pair(make_pair(0, 0), C));
    q.push(make_tuple(0,0,C));
    vector<int> result;
    
    while (!q.empty())
    {
        //int a = q.front().first.first;
        int a = get<0>(q.front());
        //int b = q.front().first.second;
        int b = get<1>(q.front());
        //int c = q.front().second;
        int c = get<2>(q.front());
        q.pop();
        
        if (cache[a][b][c] == true)
            continue;
        cache[a][b][c] = true;
        //조건 충족 시
        if (a == 0)
            result.push_back(c);
        
        //a->b
        if (a + b > B) //넘치면 안되므로
            q.push(make_tuple(a + b - B, B, c));
        else
            q.push(make_tuple(0, a + b, c));
        
        //a->c
        if (a + c > C)
            q.push(make_tuple(a + b - C, b, C));
        else
            q.push(make_tuple(0, b, a + c));
        
        //b->a
        if (b + a > A)
            q.push(make_tuple(A, b + a - A, c));
        else
            q.push(make_tuple(b + a, 0, c));
        
        //b->c
        if (b + c > C)
            q.push(make_tuple(a, b + c - C, C));
        else
            q.push(make_tuple(a, 0, b + c));
        
        //c->a
        if (c + a > A)
            q.push(make_tuple(A, b, c + a - A));
        else
            q.push(make_tuple(c + a, b, 0));
        
        //c->b
        if (c + b > B)
            q.push(make_tuple(a, B, c + b - B));
        else
            q.push(make_tuple(a, c + b, 0));
    }
    return result;
}

int main(void)
{
    cin >> A >> B >> C;
    vector<int> result = BFS();
    sort(result.begin(), result.end());
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
