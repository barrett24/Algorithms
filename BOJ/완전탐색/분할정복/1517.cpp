//
//  1517.cpp
//  alogorithms
//
//  Created by siyoung Choi on 2018. 7. 23..
//  Copyright © 2018년 siyoung Choi. All rights reserved.
//

#include <cstdio>
using namespace std;

int n;
int a[500001];
long long c;

void merge(int arr[], int start, int mid, int end) {// 조립
    int tmp[end-start];
    
    int i = start;
    int j = mid+1;
    int k = 0;
    
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        }
        else {
            c += mid - i + 1;
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= end) tmp[k++] = arr[j++];
    
    for (int i=start, j=0; i<=end; i++, j++) {
        arr[i] = tmp[j];
    }
}
void sort(int arr[], int start, int end) {//분해
    if (start < end) {
        int mid = (start + end) / 2;
        sort(arr, start, mid);// 배열의 중앙 인덱스를 기점으로 왼쪽을 정렬
        sort(arr, mid+1, end);// 배열의 중앙 인덱스를 기점으로 오른쪽을 정렬
        merge(arr, start, mid, end);// 반으로 나뉜 두 배열을 하나로 병합
    }
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    sort(a, 0, n-1);
    printf("%lld\n", c);
    return 0;
}
