//
//  main.cpp
//  3184 양
//
//  Created by 김유진 on 2020/03/05.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int dx[10]={0,0,-1,1};
int dy[10]={-1,1,0,0};
char data[400][400];
int n,m;
int o,v;
int liveO=0,liveV=0;

void func(int x, int y)
{
    if(data[x][y]=='o')
    {
        o++;
    }
    if(data[x][y]=='v')
    {
        v++;
    }
    data[x][y]='*';
    for(int i=0 ; i<4; i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X>=0 && Y>=0 && X<n && Y<m && (data[X][Y]!='#' && data[X][Y]!='*'))
        {
            func(X,Y);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",data[i]);
    }
    
    for(int i=0 ; i<n  ;i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            o=0;
            v=0;
            if(data[i][j]!='#' && data[i][j]!='*')
            {
                func(i,j);
                if(o>v)
                {
                    liveO+=o;
                }
                else{
                    liveV+=v;
                }
            }
               
        }
    }
    
    printf("%d %d",liveO, liveV);
}
