//
//  main.cpp
//  14502 연구소
//
//  Created by 김유진 on 2020/08/31.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
int n,m;
int input[10][10]={0,};
int check[10][10]={0,};
int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};
int wallCnt=0;
int result=0;
vector<pair<int, int> > virusList;

void get_not_safe(int x,int y)
{
    check[x][y]=1;
    for(int i=0 ; i<4 ;i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X>=0 && Y>=0 && X<n && Y<m &&
           check[X][Y]==0 && input[X][Y]!=1)
        {
            get_not_safe(X, Y);
        }
    }
}

vector<pair<int ,int> > wallList(5);
void randomWall(int num)
{
    if(num==3)
    {
        for(int i=0 ; i<virusList.size() ; i++)
        {
            get_not_safe(virusList[i].first, virusList[i].second);
        }
        
        int notSafe=0;
        for(int i=0 ; i<n ;i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(check[i][j]==1)
                {
                    notSafe++;
                    check[i][j]=0;
                }
            }
        }
        
        wallList.clear();
        
        int safeNum= n*m - notSafe - wallCnt-3;
        if(result < safeNum)
        {
            result=safeNum;   
        }
        return;
    }
    
    int N = num==0 ? 0 : wallList[num-1].first;
    int M = num==0 ? 0 : wallList[num-1].second+1;
    
    for(int i=N ; i<n ; i++)
    {
        for(int j= (i==N? M:0) ; j<m ; j++)
        {
            if(input[i][j]==0)
            {
                input[i][j]=1;
                wallList[num] = make_pair(i, j);
                randomWall(num+1);
                input[i][j]=0;
            }
        }
    }
}


int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i=0; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            scanf("%d",&input[i][j]);
            switch (input[i][j]) {
                case 1:
                    wallCnt++;
                    break;
                case 2:
                    virusList.push_back(make_pair(i, j));
                    
                default:
                    break;
            }
        }
    }
    randomWall(0);
    printf("%d",result);
}
