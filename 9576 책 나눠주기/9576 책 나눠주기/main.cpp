//
//  main.cpp
//  9576 책 나눠주기
//
//  Created by 김유진 on 2020/08/14.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int data[2020][2020]={0,};
int check[2020]={0,};
int n,m;
bool hasResult=false;
int result=0;
void func(int s)
{
    if(hasResult)
    {
        return;
    }
    if(s== n+m)
    {
        result++;
        hasResult=true;
        return;
    }
  
    for(int i=0 ; i<=n+m ; i++)
    {
        if(check[i]==0 && data[s][i]==1)
        {
            check[i]=1;
            func(i);
            if(hasResult)
            {
                check[i]=0;
                data[s][i]=0;
                data[i][s]=1;
                return;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        
        for(int i=0 ; i<=n+m ; i++)
        {
            check[i]=0;
            for(int j=0 ; j<=n+m ; j++)
            {
                data[i][j]=0;
            }
        }
        
        int a,b;
        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d",&a,&b);
            for(int j=a ; j<=b; j++)
            {
                data[i][j+m-1]=1;
            }
        }
        
        for(int i=m ; i<n+m ; i++)
        {
            data[i][n+m]=1;
        }
        
        result=0;
        for(int i=0 ; i<m ; i++)
        {
            check[i]=1;
            hasResult=false;
            func(i);
            check[i]=0;
        }
        printf("%d\n",result);
    }
}
