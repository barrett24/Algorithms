//
//  1037.cpp
//  baek
//
//  Created by Sean on 2018. 2. 3..
//  Copyright © 2018년 Sean. All rights reserved.
//

#include <cstdio>
int main(){
    int n,a,ma=0,mi=1000001;
    for(scanf("%d",&n);n;n--){
        scanf("%d",&a);
        ma=ma<a?a:ma;
        mi=mi>a?a:mi;
    }
    printf("%d",ma*mi);
    return 0;
}
