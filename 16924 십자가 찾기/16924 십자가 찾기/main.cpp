//
//  main.cpp
//  16924 십자가 찾기
//
//  Created by 김유진 on 2020/03/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct type
{
    int x,y,size;
};

int n, m;
int dx[5] = {0,0,-1,1};
int dy[5] = {-1,1,0,0};
int check[110][110]={0,};
char input[110][110];

void denote(int x, int y, int size)
{
    check[x][y]=1;
    for(int i=1 ; i<=size ; i++)
    {
        for(int k=0 ; k<4 ; k++)
        {
            int X = x+(dx[k]*i);
            int Y = y+(dy[k]*i);
            check[X][Y]=1;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    vector<type> result;
    for(int i=1 ; i<n-1 ; i++)
    {
        for(int j=1 ; j<m-1 ; j++)
        {
            if(input[i][j]=='*')
            {
                bool isPossible=true;
                int size=1;
                while(isPossible)
                {
                    for(int k=0 ; k<4 ; k++)
                    {
                        int X=i+(dx[k]*size);
                        int Y=j+(dy[k]*size);
                        if(!(0<=X && X<n && 0<=Y && Y<m
                           && input[X][Y]=='*'))
                        {
                            isPossible=false;
                            break;
                        }
                    }
                    if(!isPossible)
                    {
                        break;
                    }
                    size++;
                }
                if(size>1)
                {
                    type t;
                    t.x = i+1;
                    t.y = j+1;
                    t.size = size-1;
                    result.push_back(t);
                    
                    denote(i,j,size-1);
                }
            }
        }
    }
    
    bool isPossible=true;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if((check[i][j]==1 && input[i][j]=='.') ||
               (check[i][j]==0 && input[i][j]=='*'))
            {
                isPossible=false;
                break;
            }
               
        }
    }
    
    if(isPossible)
    {
        cout<<result.size()<<endl;
        for(int i=0 ; i<result.size() ; i++)
        {
            printf("%d %d %d\n",result[i].x, result[i].y, result[i].size);
        }
    }
    else
    {
        printf("-1");
    }
}
