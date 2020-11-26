//
//  main.cpp
//  17090 미로 탈출하기
//
//  Created by 김유진 on 2020/07/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n,m;
    char input[510][510];
    int check[510][510]={0,};
    
    int dx[5]={0,0,-1,1};
    int dy[5]={1,-1,0,0};
    char dd[5]={'L','R','D','U'};
    
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n  ; i++)
    {
        scanf("%s",input[i]);
    }
    
    int result=0;
    queue<pair<int,int>> v;
    
    for(int i=0 ; i<n ; i++)
    {
        
        if(input[i][0]=='L')
        {
            check[i][0]=1;
            result++;
            v.push(make_pair(i, 0));
        }
        if(input[i][m-1]=='R')
        {
            check[i][m-1]=1;
            result++;
            v.push(make_pair(i, m-1));
        }
    }
    
    for(int i=0 ; i<m ; i++)
    {
        if(input[0][i]=='U')
        {
            check[0][i]=1;
            result++;
            v.push(make_pair(0, i));
        }
        if(input[n-1][i]=='D')
        {
            check[n-1][i]=1;
            result++;
            v.push(make_pair(n-1, i));
        }
    }
    
    while(!v.empty())
    {
        int x=v.front().first;
        int y=v.front().second;
        
        for(int i=0 ; i<4 ; i++)
        {
            int X = x+dx[i];
            int Y = y+dy[i];
            if(X>=0 && Y>=0 && X<n && Y<m&&
               check[X][Y]==0 && input[X][Y]==dd[i])
            {
                v.push(make_pair(X, Y));
                check[X][Y]=1;
                result++;
            }
        }
        v.pop();
    }
    printf("%d",result);
}
