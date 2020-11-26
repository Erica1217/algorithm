//
//  main.cpp
//  2748 피보나치 수 2
//
//  Created by 김유진 on 13/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//


#include <cstdio>

int main()
{
    int n;
    long long data[100]={0,};
    scanf("%d",&n);
    
    data[0]=0;
    data[1]=1;
    for(int i=2 ; i<=n ; i++)
    {
        data[i] = data[i-1] + data[i-2];
    }
    printf("%lld",data[n]);
}
