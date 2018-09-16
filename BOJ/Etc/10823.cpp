//
//  10823.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 5..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    char c;
    long long sum = 0;
    int num = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\n':
                continue;
            case ',':
                sum += num;
                num = 0;
                break;
            default:
                num *= 10;
                num += c - '0';
                break;
        }
    }
    printf("%lld", sum + num);
    return 0;
}
