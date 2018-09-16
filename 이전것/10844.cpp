//
//  10844.cpp
//  baek
//
//  Created by Sean on 2018. 5. 2..
//  Copyright © 2018년 Sean. All rights reserved.
//

/*#include <iostream>
#include <vector>
#define div 1000000000
using namespace std;

int N, res=0;
vector<vector<int>> dp(N, vector<int>(10,0));

int main(){
    scanf("%d", &N);
    
    dp[0] = {0,1,1,1,1,1,1,1,1,1};
    
    for(int i=1; i<N; i++){
        for(int j=0; j<=9; j++){
            if(j==0)
                dp[i][j] = dp[i-1][i];
            else if(j==9)
                dp[i][j] = dp[i-1][8];
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % div;
        }
    }
    //for(int i : dp[N-1]) res = (res+i) % div;
    for(int i=0; i<=9; i++)
        res = (res+1) % div;
    printf("%d", res);
    return 0;
}*/
#include <iostream>
using namespace std;

int N;
long long D[101][101];
long long mod = 1000000000;

int main()
{
    cin.sync_with_stdio(false);//cin,cout 동기화
    
    cin >> N;
    
    for (int i = 1; i <= 9; i++) D[1][i] = 1;
    
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            D[i][j] = 0;
            
            if (j-1 >= 0) D[i][j] += D[i - 1][j - 1];
            if (j + 1 <= 9) D[i][j] += D[i - 1][j + 1];
            
            D[i][j] %= mod;
        }
    }
    
    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += D[N][i];
    }
    ans %= mod;
    
    cout << ans;
    
    return 0;
}
