//
//  main.cpp
//  6588 골드바흐의 추측
//
//  Created by 김유진 on 2020/04/21.
//  Copyright © 2020 김유진. All rights reserved.
//
#include <cstdio>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int check[1100000]={0,};
    check[1]=1;
    
    for(int i=2; i<=sqrt(1000000) ; i++)
    {
        for(int j=i+i ; j<=1000000 ; j+=i)
        {
            check[j]=1;
        }
    }
    
    while(n!=0)
    {
        for(int i=3 ; i<n ; i++)
        {
            if(check[i]==0 && check[n-i]==0)
            {
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }
        scanf("%d",&n);
    }
}
