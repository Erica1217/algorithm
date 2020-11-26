//
//  main.cpp
//  2410  2의 멱수의 합
//
//  Created by 김유진 on 2020/01/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[1000100][30]={0,};

int main()
{
    int n;
    scanf("%d",&n);

    data[1][0]=1;
    data[2][0]=1;
    data[2][1]=1;

    int temp=1;
    for(int i=0; temp<=n ; i++)
    {
        data[temp][i]=1;
        temp*=2;
    }

    int a=2;
    for(int i=3 ; i<=n ; i++)
    {
        if(i==1<<(a+1))
        {
            a++;
        }
        for(int j=0 ; j<a ; j++)
        {
            for(int k=j; k<=a ; k++)
            {
                data[i][j] = (data[i][j] + data[i-(1<<j)][k])%1000000000;
            }
        }
    }

    int result=0;
    for(int i=0 ; i<=20 ; i++)
    {
        result = (result+data[n][i])%1000000000;
    }
    printf("%d",result);
}
