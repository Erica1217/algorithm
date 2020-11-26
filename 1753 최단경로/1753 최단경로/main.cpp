//
//  main.cpp
//  1753 최단경로
//
//  Created by 김유진 on 25/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int ans[21000]={0,};

struct type{
    int start;
    int end;
    int v;
};

struct sortf{
    bool operator()(type a, type b)
    {
        if(a.v>b.v)
        {
            return true;
        }
        return false;
    }
};

priority_queue<type, vector<type>, sortf> q;
vector<type> data[21000];

int main()
{
    int V,E;
    int S; // 시작 정점의 번호
    
    scanf("%d %d",&V,&E);
    scanf("%d",&S);
    
//    입력
    int a,b,c;
    for(int i=0 ; i<E ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        type t;
        t.start = a;
        t.end = b;
        t.v = c;
        data[a].push_back(t);
        if(S==a)
        {
            q.push(t);
        }
    }
    
//    메인
    while(q.size())
    {
        type t = q.top();
        q.pop();
        
        if(ans[t.end]==0 || ans[t.end] > t.v)
        {
            ans[t.end]=t.v;
        }
        else
        {
            continue;
        }

        for(int i=0 ; i<data[t.end].size() ; i++)
        {
            int s = t.end;
            int e = data[t.end][i].end;
            int cost = t.v + data[t.end][i].v;
            if(ans[e] > cost || ans[e]==0)
            {
                type tmp;
                tmp.start = s;
                tmp.end = e;
                tmp.v = cost;
                q.push(tmp);
            }
        }
    }
    
//    출력
    for(int i=1; i<=V ; i++)
    {
        if(i==S)
            printf("0\n");
        else if(ans[i]==0)
            printf("INF\n");
        else
            printf("%d\n",ans[i]);
    }
}
