//
//  main.cpp
//  1717 집합의 표현
//
//  Created by 김유진 on 2020/04/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int parent[1100000]={0,};

int find(int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x!=y){
        parent[y]=x;
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i=1 ; i<=n ; i++)
    {
        parent[i]=i;
    }
    
    int oper,a,b;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&oper,&a,&b);
        if(oper==0) //합치기
        {
            merge(a,b);
        }
        else{
            if(find(a) == find(b))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}
