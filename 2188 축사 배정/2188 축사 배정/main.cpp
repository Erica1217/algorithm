//
//  main.cpp
//  2188 축사 배정
//
//  Created by 김유진 on 2020/08/09.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n,m;
int data[500][500]={0,};
int queue[500]={0,};
int check[500]={0,};
int end;
int result=0;
bool hasResult=false;

void func(int num, int s)
{
    if(hasResult)
        return;
    if(s==end)
    {
        hasResult=true;
        result++;
        for(int i=1 ; i<num ; i++)
        {
            data[queue[i-1]][queue[i]]=0;
            data[queue[i]][queue[i-1]]=1;
        }
        return;
    }
    
    for(int i=0 ; i<=n+m ; i++)
    {
        if(data[s][i]==1 && check[i]==0)
        {
            check[i]=1;
            queue[num]=i;
            func(num+1,i);
            if(hasResult)
                check[i]=0;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        for(int j=0 ; j<a ;j++)
        {
            scanf("%d",&b);
            data[i][b+n-1]=1;
        }
    }
    
    end = n+m;
    for(int i=n ; i<n+m ; i++)
    {
        data[i][end]=1;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        hasResult=false;
        check[i]=1;
        queue[0]=i;
        func(1,i);
        check[i]=0;
    }
    
//        for(int i=0 ; i<=n+m ; i++)
//        {
//            for(int j=0 ; j<=n+m ; j++)
//            {
//                printf("%d ",data[i][j]);
//            }
//            printf("\n");
//        }
    printf("%d\n",result);
}
