//
//  main.cpp
//  2146 다리 만들기
//
//  Created by 김유진 on 2020/07/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
int input[200][200]={0,};
int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};
int result= 1000000;
int data[110][110][11000]={0,};

void func(int num, int x, int y)
{
    for(int i=0 ; i<4 ; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X>=0 && X<n && Y>=0 && y<n && input[X][Y]==1)
        {
            input[X][Y]=num;
            func(num,X,Y);
        }
    }
}

void getMin(int start, int x, int y, int num)
{
    
    for(int i=0 ; i<4 ; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X>=0 && X<n && Y>=0 && y<n)
        {
            if(input[X][Y]!=0 && input[X][Y]!=start)
            {
                data[X][Y][start]=num+1;
                result = result<num+1 ? result:num+1;
            }
            else if(input[X][Y]==start && data[X][Y][start]==0)
            {
                data[X][Y][start]=num;
                getMin(start,X,Y,num);
            }
            else if(data[X][Y][start]==0 || data[X][Y][start]>num+1)
            {
                printf("%d %d\n",data[X][Y][start], num+1);
                printf("%d %d %d %d\n",start,x,y,num);
                data[X][Y][start]=num+1;
                getMin(start,X,Y,num+1);
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    int num=2;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            if(input[i][j]==1)
            {
                input[i][j]=num;
                func(num,i,j);
                num++;
            }
        }
    }

    num=2;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(input[i][j]==num)
            {
                getMin(num,i,j,1);
            }
        }
    }

//    for(int i=0 ; i<n ; i++)
//    {
//        for(int j=0 ; j<n ; j++)
//        {
////            printf("%d ",data[i][j][2]);
//            printf("%d ",input[i][j]);
//        }
//        printf("\n");
//    }

    printf("%d\n",result-2);
}
