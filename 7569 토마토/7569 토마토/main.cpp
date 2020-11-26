//
//  main.cpp
//  7569 토마토
//
//  Created by 김유진 on 2020/03/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[110][110][110]={0,};
int dx[7]={0,0,-1,1,0,0};
int dy[7]={1,-1,0,0,0,0};
int dh[7]={0,0,0,0,1,-1};
int n,m,h;
//int check[110][110][110]={0,};

void func(int num)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            for(int k=0 ; k<h ; k++)
            {
                if(data[i][j][k]>=1)
                {
                    for(int a=0 ; a<6 ; a++)
                    {
                        int X = dx[a]+i;
                        int Y = dy[a]+j;
                        int H = dh[a]+k;
                        if(X>=0 && X<n && Y>=0 && Y<m && H>=0 && H<h
                           &&( data[X][Y][H]==0 ))//|| (data[X][Y][H]!=-1 && data[X][Y][H]<num)))
                        {
                            data[X][Y][H]=num;
                            func(num+1);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d",&m,&n,&h);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            for(int k=0 ; k<h ; k++)
            {
                scanf("%d",&data[i][j][k]);
            }
        }
    }
    func(1);
    int max=0;
    bool hasZero=false;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            for(int k=0 ; k<h ; k++)
            {
                if(data[i][j][k]==0)
                {
                    hasZero=true;
                }
                if(data[i][j][k]>max)
                {
                    max = data[i][j][k];
                }
                printf("%d ",data[i][j][k]);
            }
            printf("\n");
        }
    }
    
    if(hasZero)
    {
        printf("-1");
    }
    else
    {
        printf("%d",max);
    }
}
