//
//  main.cpp
//  1339 단어 수학
//
//  Created by 김유진 on 2020/02/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>

int n;
char input[15][15];
int idx[30];
int data[15];
int check[15]={0,};
int N=1;

long long result=0;

void func(int num)
{
    if(num==10)
    {
        long long sum=0;
        for(int i=0 ; i<n ; i++)
        {
            int a=0;
            for(int j=0 ; j<strlen(input[i]) ; j++)
            {
                a=a*10+data[idx[input[i][j]-'A']-1];
            }
            sum+=a;
        }
        if(sum > result)
        {
            result = sum;
        }
        return;
    }
    
    for(int i=0 ; i<=9 ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            data[num]=i;
            func(num+1);
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ;i++)
    {
        scanf("%s",input[i]);
        for(int j=0 ; j<strlen(input[i]) ; j++)
        {
            if(idx[input[i][j]-'A']==0)
                idx[input[i][j]-'A']= N++;
        }
        
    }
    func(0);
    printf("%lld",result);
}
