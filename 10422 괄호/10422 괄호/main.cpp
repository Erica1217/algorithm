//
//  main.cpp
//  10422 괄호
//
//  Created by 김유진 on 2020/02/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

long long mod(long long n)
{
    return n%1000000007;
}

int main()
{
    int T;
    scanf("%d",&T);
    
    int b;
    for(int a=0 ; a<T ; a++)
    {
        scanf("%d",&b);
        
        if(b%2==1)
        {
            printf("0\n");
            continue;
        }
        
        long long data[3000]={0,};
        data[0]=1;
        data[1]=1;
        data[2]=2;
        for(int i=3 ; i<=b/2 ; i++)
        {
            for(int j=0 ; j<i ; j++)
            {
                data[i] = mod(mod(data[i-1-j] * data[j]) + data[i]);
            }
        }
        printf("%lld\n",data[b/2]);
    }
}
