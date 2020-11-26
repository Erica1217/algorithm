//
//  main.cpp
//  13460 구슬탈출2
//
//  Created by 김유진 on 2020/04/04.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;

struct type{
    int rx,ry;
    int bx,by;
    int num=0;
};

int main()
{
    char data[15][15];
    int check[15][15][15][15]={0,};
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i=0; i<n ; i++)
    {
        scanf("%s",data[i]);
    }
    
    int rx,ry;
    int bx,by;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(data[i][j]=='R')
            {
                rx=i;
                ry=j;
            }
            if(data[i][j]=='B')
            {
                bx=i;
                by=j;
            }
        }
    }
    
    deque<type> deq;
    check[rx][ry][bx][by]=1;
    type t;
    t.rx=rx;
    t.ry=ry;
    t.bx=bx;
    t.by=by;
    t.num = 0;
    
    deq.push_back(t);
    
    int dx[7]={0,0,1,-1};
    int dy[7]={1,-1,0,0};
    while(!deq.empty())
    {
        type t = deq.front();
        
        if(t.num>9)
        {
            printf("-1");
            return 0;
        }
        for(int i=0 ; i<4 ; i++)
        {
            int RX = t.rx;
            int RY = t.ry;
            int BX = t.bx;
            int BY = t.by;
            bool isRedRoll=true;
            bool isBlueRoll=true;
            bool isBlueGoal=false;
            bool isRedGoal=false;
            while(isRedRoll || isBlueRoll)
            {
                isRedRoll=false;
                isBlueRoll=false;
//                printf("[%d %d] [%d %d]\n",RX,RY,BX,BY);
                if(data[RX+dx[i]][RY+dy[i]]!='#' &&
                   !((RX+dx[i])==BX && (RY+dy[i])==BY) && !isRedGoal)
                {
                    RX+=dx[i];
                    RY+=dy[i];
                    isRedRoll=true;
                    if(data[RX][RY]=='O')
                    {
                        RX=-1;
                        RY=-1;
                        isRedGoal=true;
                    }
                }
                if(data[BX+dx[i]][BY+dy[i]]!='#' &&
                   !((BX+dx[i])==RX && (BY+dy[i])==RY) && !isBlueGoal)
                {
                    BX+=dx[i];
                    BY+=dy[i];
                    isBlueRoll=true;
                    if(data[BX][BY]=='O')
                    {
                        BX=-1;
                        BY=-1;
                        isBlueGoal=true;
                    }
                }
            }
            
            if(isBlueGoal)
            {
                continue;
            }
            else if(isRedGoal)
            {
                printf("%d\n",t.num+1);
                return 0;
            }
            
            if(check[RX][RY][BX][BY]==0)
            {
                check[RX][RY][BX][BY]=1;
                type tmp;
                tmp.rx = RX;
                tmp.ry = RY;
                tmp.bx = BX;
                tmp.by = BY;
                tmp.num = t.num+1;
                deq.push_back(tmp);
            }
            
        }
        deq.pop_front();
    }
    printf("-1");
}
