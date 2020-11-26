//
//  main.cpp
//  1916 최소비용 구하기
//
//  Created by 김유진 on 2020/08/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct type{
    int s,e,v;
    bool operator()(type a, type b)
    {
        return a.v>b.v;
    };
};

int check[1010][1010]={0,};
priority_queue<type, vector<type>, type > q;
vector<type> data[1010];
int ans[1010]={0,};

int main()
{
    int n,m;
    int start, end;
    scanf("%d",&n);
    scanf("%d",&m);
    
    int a,b,c;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        type t;
        t.s = a;
        t.e = b;
        t.v = c;
        data[a].push_back(t);
    }
    for(int i=0; i<=n ; i++)
    {
        ans[i]=-1;
    }
    scanf("%d %d",&start,&end);
    
    for(int i=0 ; i<data[start].size() ; i++)
    {
        q.push(data[start][i]);
    }
    
    while(!q.empty())
    {
        type t = q.top();
        q.pop();
        ans[t.e]=t.v;
        if(t.e == end)
        {
            break;
        }
        
        for(int i=0 ; i<data[t.e].size() ; i++)
        {
            int ns = t.e;
            int ne = data[ns][i].e;
            int cost = t.v+data[ns][i].v;
            if(ans[ne]==-1 || ans[ne]>cost)
            {
                type tt;
                tt.s=ns;
                tt.e=ne;
                tt.v=cost;
                q.push(tt);
            }
        }
    }
    printf("%d",ans[end]);
}
