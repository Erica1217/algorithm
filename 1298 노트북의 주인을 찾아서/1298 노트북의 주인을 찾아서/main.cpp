//
//  main.cpp
//  1298 노트북의 주인을 찾아서
//
//  Created by 김유진 on 2020/08/14.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int check[1000]={0,};
int n,m;
int data[1000][1000]={0,};
bool hasResult=false;
int result=0;

void func(int s)
{
    if(hasResult)
    {
        return;
    }
    if(s==n+n)
    {
        hasResult=true;
        result++;
        return;
    }
    for(int i=0 ; i<=n+n ; i++)
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
                break;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    
    int a,b;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        data[a-1][b+n-1]=1;
    }
    
    for(int i=n ; i<n+n ; i++)
    {
        data[i][n+n]=1;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        check[i]=1;
        hasResult=false;
        func(i);
        check[i]=0;
    }
    
//    for(int i=0; i<=n+n ; i++)
//    {
//        for(int j=0 ; j<=n+n ; j++)
//        {
//            printf("%d ",data[i][j]);
//        }
//        printf("\n");
    
//    }
    printf("%d\n",result);
}
