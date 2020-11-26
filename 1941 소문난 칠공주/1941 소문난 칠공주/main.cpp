//
//  main.cpp
//  1941 소문난 칠공주
//
//  Created by 김유진 on 2020/11/25.
//

#include <cstdio>
using namespace std;
char input[10][10];
int dx[5] = {0,1};
int dy[5] = {1,0};
int check[10][10]={0,};
int d[100][3]={0,};
int result=0;

void func(int num, int numS, int x, int y)
{
//    printf("%d %d %d %d [%c]\n",num,numS,x,y,input[x][y]);
    
    if(num==7)
    {
        if(numS>=4 || (x==3 && y==4))
        {
            for(int i=0 ; i<num ; i++)
            {
                int X = d[i][0];
                int Y = d[i][1];
                printf("%d %d [%c]\n",X,Y,input[X][Y]);
                if(input[X][Y]=='S')
                {
                    
                }
            }
            printf(":%d\n",numS);
            result++;
        }
        return;
    }
    
    for(int i=0 ; i<2 ; i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;
        if(X>=0 && X<5 && Y>=0 && Y<5 && check[X][Y]==0)
        {
            check[X][Y]=1;
            d[num][0]=X;
            d[num][1]=Y;
            if(input[X][Y]=='S')
            {
                func(num+1, numS+1 ,X,Y);
            }
            else
            {
                func(num+1, numS ,X,Y);
            }
            check[X][Y]=0;
        }
    }
}

int main()
{
    for(int i=0 ; i<5;  i++)
    {
        scanf("%s",input[i]);
    }
    
    func(0,0,0,0);
    printf("%d",result);
}
