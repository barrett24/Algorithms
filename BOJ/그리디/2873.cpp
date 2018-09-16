//
//  2873.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 20..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int arr[1001][1001];
int r, c;
pair<int,int> p;
string path;

int main(){
    scanf("%d %d", &r, &c);
    
    if(r%2 == 1){
        for(int i=0; i<r; i++){
            for(int j=0; j<c-1; j++)
                path += i%2 == 0 ? 'R' : 'L';
            if(i != r-1)
                path += 'D';
        }
    }
    else if(c%2 == 1){
        for(int i=0; i<c; i++){
            for(int j=0; j<r-1; j++)
                path += i%2 == 0 ? 'D' : 'U';
            if(i != c-1)
                path += 'R';
        }
    }else{
        int temp = 1000;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                scanf("%d", &arr[i][j]);
                if ((i%2 == 0 && j%2 == 1) || (i%2 == 1 && j%2 == 0)) {
                    if (arr[i][j] < temp) {
                        temp = arr[i][j];
                        p = {i, j};
                    }
                }
            }
    
    // 지나지 말아야 할 좌표의 맨 왼쪽으로 내려온 다음
    int nr = (p.first/2) * 2;
    for (int i=0; i<nr; i++) {
        for (int j=0; j<c-1; j++) {
            path += i%2 == 0 ? 'R' : 'L';
        }
        path += 'D';
    }
    
    // 좌표의 대각선 아래까지 이동하고
    int nc = p.second;
    for (int i=0; i<nc; i++) {
        path += i%2 == 0 ? "DR" : "UR";
    }
    
    // 좌표의 우측 끝으로 이동한 다음
    for (int i=nc; i<c-1; i++) {
        path += i%2 == 0 ? "RD" : "RU";
    }
    
    // 목적지까지 간다
    int mr = r - (p.first % 2 == 0 ? p.first+2 : p.first+1);
    for (int i=0; i<mr; i++) {
        path += 'D';
        for (int j=0; j<c-1; j++) {
            path += i%2 == 0 ? 'L' : 'R';
        }
    }
    }
    printf("%s\n", path.c_str());
    return 0;
}
