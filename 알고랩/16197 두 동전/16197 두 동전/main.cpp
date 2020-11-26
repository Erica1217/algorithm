//
//  main.cpp
//  16197 두 동전
//
//  Created by 김유진 on 2020/04/04.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;

struct type{
    int x1,y1;
    int x2,y2;
    int num;
};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char input[30][30]={0,};
    int check[25][25][25][25]={0,};
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    int X1=-1,X2=-1,Y1=-1,Y2=-1;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(input[i][j]=='o')
            {
                if(X1==-1|| Y1==-1)
                {
                    X1=i;
                    Y1=j;
                }
                else
                {
                    X2=i;
                    Y2=j;
                }
            }
        }
    }
    
    deque<type> data;
    type start;
    start.x1 = X1;
    start.x2 = X2;
    start.y1 = Y1;
    start.y2 = Y2;
    start.num=0;
    
    check[X1][Y1][X2][Y2]=1;
    check[X2][Y2][X1][Y1]=1;
    
    data.push_back(start);
    
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    while(!data.empty())
    {
        type t= data.front();
        if(t.num>=10)
        {
            printf("-1");
            return 0;
        }
        for(int i=0 ; i<4; i++)
        {
            int X1 = dx[i]+t.x1;
            int Y1 = dy[i]+t.y1;
            int X2 = dx[i]+t.x2;
            int Y2 = dy[i]+t.y2;
//            printf("[%d %d] [%d %d]\n",X1,Y1,X2,Y2);
            if((X1<0 || X1>=n || Y1<0 || Y1>=m)
               &&(X2<0 || X2>=n || Y2<0 || Y2>=m))
            {
//                printf("*\n");
                continue;
            }
            else if((X1<0 || X1>=n || Y1<0 || Y1>=m)
                    || (X2<0 || X2>=n || Y2<0 || Y2>=m))
            {
                printf("%d",t.num+1);
                return 0;
            }
            if(input[X1][Y1]=='#')
            {
                X1 = t.x1;
                Y1 = t.y1;
            }
            if(input[X2][Y2]=='#')
            {
                X2 = t.x2;
                Y2 = t.y2;
            }
            
            if(!((X1==X2) && (Y1==Y2))
               && check[X1][Y1][X2][Y2]==0)
            {
                check[X1][Y1][X2][Y2]=1;
                check[X2][Y2][X1][Y1]=1;
                type tmp;
                tmp.x1=X1;
                tmp.y1=Y1;
                tmp.x2=X2;
                tmp.y2=Y2;
                tmp.num = t.num+1;
                data.push_back(tmp);
            }
        }
        data.pop_front();
    }
    printf("-1");
}
