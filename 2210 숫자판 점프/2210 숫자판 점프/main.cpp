//
//  main.cpp
//  2210 숫자판 점프
//
//  Created by 김유진 on 2020/04/05.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int check[11][11][11][11][11][11]={0,};

int dx[5]={0,0,-1,1};
int dy[5]={-1,1,0,0};
int data[10]={0,};
int input[8][8];
int result=0;
void func(int num,int x, int y)
{
    if(num>6)
    {
        if(check[data[0]][data[1]][data[2]][data[3]][data[4]][data[5]]==0)
        {
            check[data[0]][data[1]][data[2]][data[3]][data[4]][data[5]]=1;
            result++;
        }
        return;
    }
    
    for(int i=0; i<4 ;i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;
        if(X>=0 && X<5 && Y>=0 && Y<5)
        {
            data[num]=input[X][Y];
            func(num+1,X,Y);
        }
    }
}
int main()
{
    for(int i=0 ; i<5 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    for(int i=0 ; i<5 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            func(0,i,j);
        }
    }
    printf("%d",result);
    
}
