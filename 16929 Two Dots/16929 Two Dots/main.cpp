//
//  main.cpp
//  16929 Two Dots
//
//  Created by 김유진 on 2020/07/23.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n, m;
char data[110][110];
int check[110][110];
bool result = false;

int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};
void func(int num, int x, int y, int bx, int by)
{
    for(int i=0 ; i<4 ; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X>=0 && X<n && Y>=0 && Y<m && data[x][y]==data[X][Y])
        {
            if(check[X][Y]==0)
            {
                check[X][Y]=num;
                func(num,X,Y,x,y);
            }
            else if(!(bx==X && by==Y)&& check[X][Y]==num)
            {
                result=true;
//                printf("%d %d / %d %d /%d %d \n",X,Y,bx,by,x,y);
//                for(int a=0 ; a<n ; a++)
//                {
//                    for(int b=0 ; b<m ; b++)
//                    {
//                        printf("%d ",check[a][b]);
//                    }
//                    printf("\n");
//                }
                return;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;  i<n ; i++)
    {
        scanf("%s",data[i]);
    }
    
    int num=1;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(check[i][j]==0)
            {
                check[i][j]=num;
                func(num,i,j,i,j);
                num++;
                if(result)
                {
                    printf("Yes");
                    return 0;
                }
            }
        }
    }
    printf("No");
}
