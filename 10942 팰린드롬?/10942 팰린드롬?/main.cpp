//
//  main.cpp
//  10942 팰린드롬?
//
//  Created by 김유진 on 2020/03/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n,m;
int input[2020];
int data[2020][2020]={0,};

int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    for(int i=n-1 ; i>=0 ; i--)
    {
        data[i][i]=1;
        for(int j=i+1 ; j<n ; j++)
        {
            if(input[i]==input[j] && (data[i+1][j-1]==1 || j-1==i ))
            {
                data[i][j]=1;
            }
        }
    }
    
    scanf("%d",&m);
    int s,e;
    for(int a=0 ; a<m ; a++)
    {
        scanf("%d %d",&s,&e);
        printf("%d\n",data[s-1][e-1]);
    }
}
