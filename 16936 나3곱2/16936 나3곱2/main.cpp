//
//  main.cpp
//  16936 나3곱2
//
//  Created by 김유진 on 2020/03/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int result[110];
int check[110];
int n;
long long input[110];
int data[110][110];

bool hasResult=false;

void func(int num, int start)
{
    if(hasResult)
    {
        return;
    }
    if(num==n)
    {
        hasResult=true;
        for(int i=0 ; i<n ; i++)
        {
            printf("%lld ",input[result[i]]);
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        if(data[start][i]==1 && check[i]==0)
        {
            check[i]=1;
            result[num] = i;
            func(num+1,i);
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%lld",&input[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(input[i]%3==0 && input[i]/3 == input[j])
            {
                data[i][j]=1;
            }
            
            if(input[i]*2 == input[j])
            {
                data[i][j]=1;
            }
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        result[0]=i;
        func(1,i);
        if(hasResult)
        {
            break;
        }
    }
}
