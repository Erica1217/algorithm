//
//  main.cpp
//  1967 트리의 지름
//
//  Created by 김유진 on 2020/09/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;
int n;
vector<pair<int ,int> > data[11000];
int check[11000]={0,};
int maxD=0;
int result;
void find(int node, int d)
{
    if(d>maxD)
    {
        maxD=d;
        result=node;
    }
    for(int i=0 ; i<data[node].size() ; i++)
    {
        int t = data[node][i].first;
        if(check[t]==0)
        {
            check[t]=1;
            find(t,d+data[node][i].second);
        }
    }
}

int main()
{
    scanf("%d",&n);
    int a,b,c;
    for(int i=0 ; i<n-1 ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        data[a].push_back(make_pair(b, c));
        data[b].push_back(make_pair(a, c));
    }
    find(1,0);
    for(int i=1 ; i<=n ; i++)
    {
        check[i]=0;
    }
    find(result,0);
    printf("%d",maxD);
}
