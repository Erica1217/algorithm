//
//  main.cpp
//  가장 빠른 길 찾기
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int n,m;

int main()
{
//    freopen("queue_05.in","r",stdin);
//    freopen("queue_05.out","w",stdout);
    
    cin>>n>>m;
    int data[110][110]={0,};
    int check[110][110]={0,};
    deque<pair<int, int> > location;
    deque<int> value;
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            scanf("%1d",&data[i][j]);
        }
    }
    
    
    int dx[6]={-1,1,0,0};
    int dy[6]={0,0,-1,1};
    
    location.push_back(make_pair(n-1,0));
    value.push_back(1);
    check[n-1][0]=1;
    while(!location.empty())
    {
        int x=location.front().first;
        int y=location.front().second;
        int v=value.front();

        if(x==0 && y==m-1)
        {
            cout<<v;
            return 0;
        }
        
        for(int i=0 ; i<4 ; i++)
        {
            int X=dx[i]+x;
            int Y=dy[i]+y;
            if(X>=0 && X<n &&Y>=0 && Y<m
               && check[X][Y]==0 && data[X][Y]==0 )
            {
                location.push_back(make_pair(X, Y));
                value.push_back(v+1);
                check[X][Y]=1;
            }
        }
        location.pop_front();
        value.pop_front();

    }
    cout<<"-1";
}
