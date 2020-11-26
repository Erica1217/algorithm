//
//  main.cpp
//  소마2차 2
//
//  Created by 김유진 on 2020/04/26.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int parent[310000]={0,};
int xy[310000][4]={0,};
int grid[310000][5]={0,};
int find(int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    return parent[x]=find(parent[x]);
}

void merge(int x, int y)
{
    x=find(x);
    y=find(y);
    if(x<y)
    {
        int t=y;
        y=x;
        x=t;
    }
    if(x!=y)
    {
        parent[x]=y;
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d %d",&xy[i][0], &xy[i][1]);
    }
    
    for(int i=1; i<=n ; i++)
     {
         parent[i]=i;
     }
    
    int a,b;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        if(parent[a]!=parent[b])
        {
            merge(a,b);
        }
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        int p = find(i);
        int x= xy[i][0];
        int y= xy[i][1];
        if(grid[p][0]==0 || grid[p][0]>x)
        {
            grid[p][0]=x;
        }
        if(grid[p][1]==0 || grid[p][1]<x)
        {
            grid[p][1]=x;
        }
        if(grid[p][2]==0 || grid[p][2]>y)
        {
            grid[p][2]=y;
        }
        if(grid[p][3]==0 || grid[p][3]<y)
        {
            grid[p][3]=y;
        }
    }
    
    long long result=0;
    for(int i=1 ; i<=n ; i++)
    {
        long long minX=grid[i][0];
        long long maxX=grid[i][1];
        long long minY=grid[i][2];
        long long maxY=grid[i][3];
        long long r = (maxX-minX)*2 + (maxY-minY)*2;
//        printf("%d %d | %d %d\n",minX,maxX,minY,maxY);
        if(result<r)
        {
            result=r;
        }
    }
    printf("%lld",result);
}
