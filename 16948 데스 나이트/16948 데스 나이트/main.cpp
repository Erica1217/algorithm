//
//  main.cpp
//  16948 데스 나이트
//
//  Created by 김유진 on 2020/07/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;
//(r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)
int dx[10]={-2,-2,0,0,2,2};
int dy[10]={-1,1,-2,2,-1,1};
struct s{
    int x;
    int y;
    int n;
};
int main()
{
    int N;
    int data[220][220]={0,};
    int r1,c1, r2,c2;
    scanf("%d",&N);
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    
    deque<s> deq;
    s d;
    d.x=r1;
    d.y=c1;
    d.n=1;
    deq.push_back(d);
    
    while(!deq.empty())
    {
        int x =deq.front().x;
        int y =deq.front().y;
        int n =deq.front().n;
        
        if(x==r2 && y==c2)
        {
            printf("%d",n-1);
            return 0;
        }
        
        for(int i=0 ; i<6 ; i++)
        {
            int X = x+dx[i];
            int Y = y+dy[i];
            if(X>=0 && Y>=0
               && X<N && Y<N
               && data[X][Y]==0)
            {
//                printf("%d %d [%d]\n",X,Y,n);
//                printf("%d %d\n",x,y);
                data[X][Y]=n+1;
                s d;
                d.x=X;
                d.y=Y;
                d.n = n+1;
                deq.push_back(d);
            }
        }
        deq.pop_front();
    }
    printf("-1");
    
}
