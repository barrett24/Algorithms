//
//  2805.cpp
//  baek
//
//  Created by Sean on 2018. 5. 16..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000000

int height[MAX_SIZE];

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    int max_height = 0;
    
    for (int i = 0; i < n; i++)
        scanf("%d", height + i);
    for (int i = 0; i < n; i++)
        max_height = height[i] > max_height ? height[i] : max_height;
    
    int left = 1, right = max_height;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = 0;
        
        for (int i = 0; i < n; i++)
            sum += height[i] - mid > 0 ? height[i] - mid : 0;
        
        if (sum < m)
            right = mid - 1;
        else 
            left = mid + 1;
    }
    
    printf("%d\n", right);
    
    return 0;
}
