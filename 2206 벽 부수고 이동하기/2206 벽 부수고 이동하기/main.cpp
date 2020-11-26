//
//  main.cpp
//  2206 벽 부수고 이동하기
//
//  Created by 김유진 on 21/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
int input[1100][1100]={0,};
int data[1010000][10]={0,}; // x좌표 / y좌표 / 벽돌 여부 /거리
int check[5][1100][1100]={0,}; //1. 벽돌 /2. x좌표 / 3. y좌표

bool is_correct_location(int x, int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return false;
    }
    return true;
}

int main()
{
    cin>>n>>m;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            scanf("%1d",&input[i][j]);
            if(input[i][j]==1)
            {
                input[i][j]=-1;
            }
        }
    }
    
    int dx[5] = {0,0,-1,1};
    int dy[5] = {1,-1,0,0};
    
    int start=0;
    int end=0;
    
    data[0][0]=0;
    data[0][1]=0;
    data[0][2]=0;
    data[0][3]=1;
    check[0][0][0]=1;
    
    end++;
    while(start<end)
    {
        int x = data[start][0];
        int y = data[start][1];
        int b = data[start][2];
        int d = data[start][3];
        
//        printf("** %d %d %d %d\n",x,y,b,d);
        if(x==n-1 && y==m-1)
        {
            cout<<d;
            return 0;
        }
        
        for(int j=0 ; j<4 ; j++)
        {
            // 갈 수 있으면
            int X = x+dx[j];
            int Y = y+dy[j];
//            if(is_correct_location(X,Y) && input[X][Y]==-1)
//                printf("[%d %d %d]\n",X,Y,b);
            if(is_correct_location(X,Y)
               && input[X][Y] != -1
               && check[b][X][Y]==0)
            {
                check[b][X][Y]=1;
                data[end][0] = X;
                data[end][1] = Y;
                data[end][2] = b;
                data[end][3] = d+1;
                end++;
            }/* 벽으로 막혀 있으면*/
            else if(is_correct_location(X,Y)
               && (input[X][Y] ==-1 && b==0)
               && check[b][X][Y]==0)
            {
                
                check[1][X][Y]=1;
                data[end][0] = X;
                data[end][1] = Y;
                data[end][2] = 1;
                data[end][3] = d+1;
                end++;
            }
        }
        start++;
    }
    cout<<"-1";
}
