//
//  main.cpp
//  11725 트릐의 부모찾기
//
//  Created by 김유진 on 2020/08/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> data[110000];
    int parent[110000]={0,};
    scanf("%d",&n);
    int a,b;
    for(int i=0 ; i<n-1 ; i++)
    {
        scanf("%d %d",&a,&b);
        data[a].push_back(b);
        data[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0 ; i<data[cur].size(); i++)
        {
            int a=data[cur][i];
            if(parent[a]==0)
            {
                q.push(a);
                parent[a]=cur;
            }
        }
    }
    
    for(int i=2 ; i<=n ; i++)
    {
        printf("%d\n",parent[i]);
    }
}
