//
//  14696.cpp
//  baek
//
//  Created by Sean on 2018. 5. 24..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<int> A, B;
    
    for(int i=1; i<=N; i++){
        int Acard, Bcard;
        int A1=0,A2=0,A3=0,A4=0;
        int B1=0,B2=0,B3=0,B4=0;
        
        scanf("%d", &Acard);
        for(int j=1; j<=Acard; j++){
            int temp;
            scanf("%d", &temp);
            A.push_back(temp);
            if(temp == 4) A4++;
            if(temp == 3) A3++;
            if(temp == 2) A2++;
            if(temp == 1) A1++;
        }
        scanf("%d", &Bcard);
        for(int k=1; k<=Bcard; k++){
            int temp;
            scanf("%d", &temp);
            A.push_back(temp);
            if(temp == 4) B4++;
            if(temp == 3) B3++;
            if(temp == 2) B2++;
            if(temp == 1) B1++;
        }
        if(A4>B4) printf("A\n");
        if(A4<B4) printf("B\n");
        if(A4==B4){
            if(A3>B3) printf("A\n");
            if(A3<B3) printf("B\n");
            if(A3==B3){
                if(A2>B2) printf("A\n");
                if(A2<B2) printf("B\n");
                if(A2==B2){
                    if(A1>B1) printf("A\n");
                    if(A1<B1) printf("B\n");
                    if(A1==B1){
                        printf("D\n");
                    }
                }
            }
        }
        A.clear(); B.clear();
    }
    return 0;
}
