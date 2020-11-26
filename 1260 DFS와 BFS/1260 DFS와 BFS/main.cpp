//
//  main.cpp
//  1260 DFS와 BFS
//
//  Created by 김유진 on 2020/03/07.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;

int n,m,v;
int data[1010][1010]={0,};

int dfsResult[1010]={0,};
int dfsCheck[1010]={0,};
int dfsNum=0;

int bfsCheck[1010]={0,};
int bfsResult[10100]={0,};

void func(int current)
{
    for(int i=1 ; i<=n ; i++)
    {
        if(data[i][current]==1 && dfsCheck[i]==0)
        {
            dfsCheck[i]=1;
            dfsResult[dfsNum++]=i;
            func(i);
        }
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&v);
    
    int a,b;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        data[a][b]=1;
        data[b][a]=1;
    }
    
    dfsCheck[v]=1;
    func(v);
    printf("%d ",v);
    for(int i=0 ; i<dfsNum ; i++)
    {
        printf("%d ",dfsResult[i]);
    }
    printf("\n");
    
    deque<int> queue;
    bfsCheck[v]=1;
    queue.push_back(v);
    printf("%d ",v);
    while(!queue.empty())
    {
        int crt = queue[0];
        for(int i=1 ; i<=n ; i++)
        {
            if(bfsCheck[i]==0 && data[i][crt]==1)
            {
                bfsCheck[i]=1;
                printf("%d ",i);
                queue.push_back(i);
            }
        }
        queue.pop_front();
    }
}
