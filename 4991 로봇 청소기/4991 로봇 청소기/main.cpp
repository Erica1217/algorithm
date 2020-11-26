//
//  main.cpp
//  4991 로봇 청소기
//
//  Created by 김유진 on 2020/08/02.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct t{
    int x;
    int y;
    int num;
};

int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};

int n;
int res=2100000000;

int main()
{
    while(1)
    {
        int w,h;
        char input[30][40]={0,};

        deque<pair<int, int>> dirty;
        scanf("%d %d",&w,&h);
        if(w==0 && h==0){
            return 0;
        }
        
        for(int i=0 ; i<h ; i++)
        {
            scanf("%s",input[i]);
        }
        
        for(int i=0 ; i<h ; i++)
        {
            for(int j=0 ; j<w ; j++)
            {
                if(input[i][j]=='o')
                {
                    dirty.push_front(make_pair(i, j));
                }
                else if(input[i][j]=='*')
                {
                    dirty.push_back(make_pair(i, j));
                }
            }
        }
        
        int dis[15][15]={0,};
        
        for(int a=0 ; a<dirty.size() ; a++)
        {
            for(int b=a+1 ; b<dirty.size() ; b++)
            {
                deque<t> q;
                int check[30][30]={0,};
                t tt;
                tt.x =dirty[a].first;
                tt.y = dirty[a].second;
                tt.num=0;
                q.push_back(tt);
                check[tt.x][tt.y] = 1;
                int desX=dirty[b].first;
                int desY=dirty[b].second;
                dis[a][b]=-1;
                dis[b][a]=-1;
                do{
                    int x = q.front().x;
                    int y = q.front().y;
                    int num = q.front().num;
                    if(x==desX && y==desY)
                    {
                        dis[a][b]=q.front().num;
                        dis[b][a]=q.front().num;
                        break;
                    }
                    for(int i=0 ; i<4 ; i++)
                    {
                        int X = x+dx[i];
                        int Y = y+dy[i];
                        if(X>=0 && Y>=0 && X<h && Y<w && check[X][Y]==0
                           && input[X][Y]!='x')
                        {
                            t tt;
                            tt.x = X;
                            tt.y = Y;
                            tt.num =num+1;
                            check[X][Y]=num+1;
                            q.push_back(tt);
                        }
                    }
                    q.pop_front();
                }while(!q.empty());
                if(q.empty())
                {
                    res=-1;
                }
            }
        }
        
        n=dirty.size();
        if(res!=-1)
        {
            vector<int> v;
            for(int i=0 ; i<n ; i++)
            {
                v.push_back(i);
            }
            
            do{
                int sum=0;
                for(int i=1 ; i<n ; i++)
                {
                    int a=v[i-1];
                    int b=v[i];
                    sum+=dis[a][b];
                }
                res = res>sum?sum:res;
            }while(next_permutation(v.begin()+1, v.end()));
        }
        printf("%d\n",res);
        res=2100000000;
    }
}
