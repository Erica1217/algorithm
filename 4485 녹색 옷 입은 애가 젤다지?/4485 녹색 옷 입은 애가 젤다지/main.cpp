//
//  main.cpp
//  4485 녹색 옷 입은 애가 젤다지?
//
//  Created by 김유진 on 2020/08/07.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int input[130][130]={0,};
int data[130][130]={0,};
int n;

struct type{
//    public :
    int x;
    int y;
    int v;
};
bool operator<(type a,  type b)
{
    return a.v>b.v;
}

void func(int x, int y, int sum)
{
    if(x==n-1 && y==n-1)
    {
        return;
    }
    
    for(int i=0 ; i<4 ; i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;
        if(X>=0 && Y>=0 && X<n && Y<n &&
           (data[X][Y]==-1 || data[X][Y]>sum + input[X][Y]))
        {
            data[X][Y]=sum+input[X][Y];
            func(X,Y,sum+input[X][Y]);
        }
    }
}

int main()
{
    int num=1;
    do{
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                scanf("%d",&input[i][j]);
            }
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                data[i][j]=-1;
            }
        }
        
        data[0][0]=input[0][0];
//        func(0,0,input[0][0]);
        
        priority_queue<type, vector<type> > q;
        type t;
        t.x=0;
        t.y=0;
        t.v=input[0][0];
        q.push(t);
        while(!q.empty())
        {
            type t =q.top();
            int x=t.x;
            int y=t.y;
            int sum = t.v;
            q.pop();
        
            for(int i=0 ; i<4 ; i++)
            {
                int X = dx[i]+x;
                int Y = dy[i]+y;
                if(X>=0 && Y>=0 && X<n && Y<n &&
                   (data[X][Y]==-1 || data[X][Y]>sum + input[X][Y]))
                {
                    data[X][Y]=sum+input[X][Y];
                    type tt;
                    tt.x =X;
                    tt.y = Y;
                    tt.v  =sum+input[X][Y];
                    q.push(tt);
                }
            }
        }
        printf("Problem %d: %d\n",num,data[n-1][n-1]);
        num++;
    }
    while(true);
}
