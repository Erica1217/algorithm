//
//  main.cpp
//  11376 열혈강호2
//
//  Created by 김유진 on 2020/08/09.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n,m;
int data[2100][2100]={0,};
int check[2100]={0,};
bool hasResult=false;
int result=0;
void func(int s)
{
    if(hasResult)
        return;
    if(s==n+m)
    {
        hasResult=true;
        result++;
        return ;
    }
    for(int i=0 ; i<=n+m ; i++)
    {
        if(data[s][i]==1 && check[i]==0)
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
    scanf("%d %d",&n,&m);
    
    int a,b;
    for(int i=0; i<n ; i++)
    {
        scanf("%d", &a);
        for(int j=0 ; j<a ; j++)
        {
            scanf("%d",&b);
            data[i][b+n-1]=1;
        }
    }
    
    for(int i=n ; i<n+m ; i++)
    {
        data[i][n+m]=1;
    }
    
    for(int i=0 ;i<n; i ++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            hasResult=false;
            check[i]=1;
            func(i);
            check[i]=0;
        }
    }
    printf("%d",result);
}
