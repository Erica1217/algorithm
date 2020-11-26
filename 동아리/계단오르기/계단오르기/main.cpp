//
//  main.cpp
//  계단오르기
//
//  Created by 김유진 on 2020/03/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,m;
    int check[110000];
    scanf("%d %d",&n,&m);
    int data[110000];
    data[1]=1;
    data[2]=2;
    int b;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d",&b);
        check[b]=1;
        data[b]=0;
    }
    
    int data2[110000];
    data2[1]=1;
    data2[2]=2;
    for(int i=3 ; i<=n ; i++)
    {
        data2[i] = (data2[i-1]+data2[i-2])%1000000007;
        printf("%d ",data2[i]);
    }
    
    int a=2;
    for(int i=3 ; i<=n ; i++)
    {
        if(check[i]==1)
        {
            data[i] = 0;
        }
        else if(check[i-1]==1)
        {
            data[i] = data[i-2];
        }
        else if(check[i-2]==1)
        {
            data[i] = data[i-1];
            a=2;
        }
        else
        {
            printf("%d %d [%d]\n",data[i-1], data2[a],a);
            data[i] = data[i-1] + data2[a];
            a++;
        }
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        printf("%d ",data[i]);
    }
    printf("%d",data[n]);
}
