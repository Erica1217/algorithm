//
//  main.cpp
//  1202 보석 도둑
//
//  Created by 김유진 on 2020/03/05.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;

struct sortf{
    bool operator() (pair<int, int> a, pair<int ,int> b)
    {
        if(a.first < b.first)
        {
            return 0;
        }
        else if(a.first == b.first && a.second > b.second)
        {
            return 0;
        }
        return 1;
    }
};

int main()
{
    int n,k;
    long long result=0;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>,sortf> q;
    priority_queue<int, vector<int>> data;
    priority_queue<int, vector<int>, greater<int> > bags;
    scanf("%d %d",&n,&k);
    
    int m,v;
    for(int i=0 ; i<n;  i++)
    {
        scanf("%d %d",&m,&v);
        q.push(make_pair(m,v));
    }
    
    int c;
    for(int i=0 ; i<k ; i++)
    {
        scanf("%d",&c);
        bags.push(c);
    }
    
    vector<pair<int, int>> expensive;
    for(int i=0 ; i<k ; i++)
    {
        int bag = bags.top();
        bags.pop();
        
        while(!q.empty() && q.top().first <= bag)
        {
            data.push(q.top().second);
            q.pop();
        }
        if(!data.empty())
        {
            result+=data.top();
            data.pop();
        }
    }
    printf("%lld",result);
}
