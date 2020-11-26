//
//  main.cpp
//  11377 열혈강호 3
//
//  Created by 김유진 on 2020/08/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n,m,k;
int data[2020][2020]={0,};
int check[2020]={0,};
int result=0;
int job[2020]={0,};
bool hasResult=false;
void func(int s)
{
    if(hasResult)
    {
        return;
    }
    if(s==n+m)
    {
        result++;
        hasResult=true;
        return;
    }
    
    for(int i=0 ; i<=n+m ; i++)
    {
        if(!check[i] && data[s][i])
        {
            check[i]=1;
            func(i);
            if(hasResult)
            {
                check[i]=0;
                data[s][i]=0;
                data[i][s]=1;
                break;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        for(int j=0 ; j<a; j++)
        {
            scanf("%d",&b);
            data[i][b+n-1]=1;
        }
        job[i]=a;
    }
    
    for(int i=n; i<n+m ; i++)
    {
        data[i][n+m]=1;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        check[i]=1;
        hasResult=false;
        func(i);
        check[i]=0;
        job[i]-= hasResult ? 1:0;
    }
    
    
    for(int i=0 ; i<n ; i++)
    {
        if(job[i]==0)
        {
            continue;
        }
        hasResult = false;
        check[i]=1;
        func(i);
        check[i]=0;
        if(hasResult)
        {
            k--;
        }
        if(k==0)
        {
            break;
        }
    }
    printf("%d\n",result);
}
