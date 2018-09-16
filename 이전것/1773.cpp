//
//  1773.cpp
//  baek
//
//  Created by Sean on 2018. 4. 5..
//  Copyright © 2018년 Sean. All rights reserved.
//

/*#include <iostream>
using namespace std;

int N, C;
int cnt=0;
int arr[2000001]={0,};
int data[101]={0,};

int main(){
    scanf("%d %d",&N, &C);
    for(int i=1; i<=N; i++)
        cin >> data[i];

    for(int i=1; i<=C; i++){
        for(int j=1; j<=N; j++){
            arr[i*data[j]] = 1;
        }
    }
    for(int i=1; i<=C; i++){
        if(arr[i]==1) cnt++;
    }
    printf("%d", cnt);
    return 0;
}*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> pop;
    int cnt = 0;
    int stu = 0, time = 0, time_long = 0, plus = 0;
    
    cin >> stu >> time_long;
    
    pop.resize(time_long + 1);
    
    for (int i = 0; i < stu; i++)
    {
        cin >> time;
        plus = time;
        for (int j = 0; ;j++)
        {
            if (time > time_long)
                break;
            else
            {
                pop[time]++;
                time += plus;
            }
        }
    }
    
    for (int k = 1; k <= time_long; k++)
    {
        if (pop[k] != 0)
            cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}
