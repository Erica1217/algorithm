//
//  main.cpp
//  15653 구츨 탈출 4
//
//  Created by 김유진 on 2020/02/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

struct location{
    int rx;
    int ry;
    int bx;
    int by;
    int n;
};


int main()
{
    int n,m;
    char data[15][15];
    int check[15][15][15][15]={0,};
    int dx[5]={0,0,-1,1};
    int dy[5]={-1,1,0,0};
    queue<location> q;
    scanf("%d %d",&n, &m);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",data[i]);
    }
    
    location l;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(data[i][j]=='R')
            {
                l.rx=i;
                l.ry=j;
                data[i][j]='.';
            }
            else if(data[i][j]=='B')
            {
                l.bx=i;
                l.by=j;
                data[i][j]='.';
            }
        }
    }
    l.n=0;
    check[l.rx][l.ry][l.bx][l.by]=1;
    q.push(l);
    
    while(!q.empty())
    {
        location loc= q.front();
        if(data[loc.rx][loc.ry]=='O' && data[loc.bx][loc.by]!='O')
        {
            printf("%d",loc.n);
            return 0;
        }

        for(int i=0 ; i<4; i++)
        {
            location right;
            right = loc;
//            printf("rig %d %d %d %d -> ",right.rx, right.ry, right.bx, right.by);
//            printf("loc %d %d %d %d\n",loc.rx,loc.ry, loc.bx, loc.by);
            bool rStop=false;
            bool bStop=false;
            bool blueGoal=false;
            bool redGoal=false;
            int max = n>m ? n : m;
            for(int j=0 ; j<max ; j++)
            {
                int X = right.rx+dx[i];
                int Y = right.ry+dy[i];
                if(!rStop &&
                   right.rx+dx[i]<n && right.rx+dx[i]>=0 &&
                   right.ry+dy[i]<m && right.ry+dy[i]>=0 &&
                   data[X][Y]!='#')
                {
                    
                    if(!(right.bx==right.rx+dx[i] && right.by == right.ry+dy[i])){
                        if(data[X][Y]=='O')
                        {
                            redGoal=true;
                        }
                        right.rx+=dx[i];
                        right.ry+=dy[i];
                    }
                }else {
                    rStop=true;
                }
                
                X=right.bx+dx[i];
                Y=right.by+dy[i];
                if(!bStop &&
                   right.bx+dx[i]<n && right.bx+dx[i]>=0 &&
                   right.by+dy[i]<m && right.by+dy[i]>=0 &&
                   data[X][Y]!='#')
                {
                    if(data[X][Y]=='O')
                    {
                        blueGoal=true;
                    }
                    
                    if(!(right.rx==right.bx+dx[i] && right.ry == right.by+dy[i]))
                    {
                        right.bx+=dx[i];
                        right.by+=dy[i];
                    }
                }
                else{
                    bStop=true;
                }
            }
            
//            printf("%d %d %d %d\n",right.rx, right.ry, right.bx, right.by);
//            printf("%d %d %d %d ",right.rx, right.ry, right.bx, right.by);
//            printf(blueGoal?"true\n":"false\n");
            
            if(redGoal && !blueGoal)
            {
                printf("%d",loc.n+1);
                return 0;
            }
            
            if(check[right.rx][right.ry][right.bx][right.by]==0 && !blueGoal)
            {
                right.n+=1;
                q.push(right);
                check[right.rx][right.ry][right.bx][right.by]=1;
            }
        }
        q.pop();
    }
    printf("-1");
}
