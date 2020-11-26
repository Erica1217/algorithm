//
//  main.cpp
//  3197 백조의 호수
//
//  Created by 김유진 on 2020/02/25.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>

using namespace std;

char input[1600][1600];
int check[1600][1600];
int swan[1500][1500];

struct grid{
    int x;
    int y;
    int n;
    int l;
};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    deque<grid> data;
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    
    bool findL=false;
    int numL=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0; j<m ; j++)
        {
            if(input[i][j]=='L')
            {
                grid g;
                g.x=i;
                g.y=j;
                g.n=0;
                g.l=1;
                data.push_back(g);
                check[i][j]=1;
                findL=true;
                numL++;
//                break;
            }
//            else if(input[i][j]=='L')
//            {
//                numL++;
//            }
        }
    }
    
    do{
        grid front = data.front();
        data.pop_front();
        int x = front.x;
        int y = front.y;
        int l= front.l;
        int num= front.n;
        
        printf("%d %d %d %d\n",x,y,l,num);
        if(l==numL)
        {
            printf("%d",num);
            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<m ; j++)
                {
                    printf("%d ",check[i][j]);
                }
                printf("\n");
            }
            
            return 0;
        }
        
        for(int k=0 ; k<4 ; k++)
        {
            int X=x+dx[k];
            int Y=y+dy[k];
            if(X>=0 && X<n &&
               Y>=0 &&Y<m )
            {
                swan[X][Y]+=l;
                if(swan[X][Y]==numL)
                {
                    printf("%d\n",num);
                    break;
                }
                if(check[X][Y]==0)
                {
                    check[X][Y]=1;
                    grid g;
                    g.x=X;
                    g.y=Y;
                    g.l=l;
                    if(input[X][Y]=='.')
                    {
                        g.n=num;
                        data.push_front(g);
                    }
                    else if(input[X][Y]=='X')
                    {
                        g.n=num+1;
                        data.push_back(g);
                    }
                    else if(input[X][Y]=='L')
                    {
                        g.n=num;
                        g.l=swan[X][Y]+l;
                        data.push_front(g);
                    }
                    check[X][Y]=g.n+1;
                }
            }
        }
    }while(!data.empty());
    
    for(int i=0 ; i<n ; i++)
   {
       for(int j=0 ; j<m ; j++)
       {
           printf("%d ",swan[i][j]);
       }
       printf("\n");
   }
}
