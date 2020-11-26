//
//  main.cpp
//  1929 소수구하기
//
//  Created by 김유진 on 2020/07/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <math.h>
using namespace std;
int data[1100000]={0,};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    data[1]=1;
    data[2]=0;
    data[3]=0;
    for(int i=2; i<=sqrt(m) ; i++)
    {
        if(data[i]==1)
            continue;
        for(int j=i*2 ; j<=m ; j+=i)
        {
            data[j]=1;
        }
    }
    for(int i=n ; i<=m ; i++)
    {
        if(data[i]==0)
        {
            printf("%d\n",i);
        }
    }
}
