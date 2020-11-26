//
//  main.cpp
//  1976 여행가자
//
//  Created by 김유진 on 2020/04/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int n,m;
int data[300][300]={0,};
int parent[300]={0,};

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
    x = find(x);
    y = find(y);
    if(x!=y)
    {
        parent[x] = y;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i=1 ; i<=n ; i++)
    {
        parent[i]=i;
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n; j ++)
        {
            scanf("%d ",&data[i][j]);
            if(data[i][j]==1)
            {
                merge(i+1,j+1);
            }
        }
    }
    int travel[1100]={0,};
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d",&travel[i]);
    }
    
    int r = find(travel[0]);
    bool isPossible=true;
    for(int i=1 ; i<m ; i++)
    {
        if(r!=find(travel[i]))
        {
            isPossible=false;
        }
        printf("%d %d\n",i,find(travel[i]));
    }
    printf(isPossible?"YES\n":"NO\n");

}
