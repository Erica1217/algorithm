//
//  main.cpp
//  2606 바이러스
//
//  Created by 김유진 on 2020/04/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int n,m;
int parent[1100]={0,};
int find(int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int a,int b)
{
     a = find(a);
     b = find(b);
    if(a!=b)
    {
        parent[a] = b;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int a,b;
    
    for(int i=1 ; i<=n ; i++)
    {
        parent[i]=i;
    }
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        merge(a,b);
    }
    int result=0;
    int r = find(1);
    for(int i=2 ; i<=n ; i++)
    {
        if(find(i)==r)
        {
            result++;
        }
    }
    printf("%d",result);
}
