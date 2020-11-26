//
//  main.cpp
//  방의 크기 구하기
//
//  Created by 김유진 on 2020/04/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,m;
int input[110][110]={0,};
int roomSize=0;
void func(int num,int x, int y)
{
    for(int i=0 ; i<4 ; i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;
        if(X>=0&& Y>=0 && X<n && y<m && input[X][Y]==0)
        {
            roomSize++;
            input[X][Y]=num;
            func(num,X,Y);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        string s;
        for(int i=0 ; i<n ;i++)
        {
            cin>>s;
            for(int j=0 ; j<m ; j++)
            {
                if(s.at(j)=='+')
                {
                    input[i][j]=-1;
                }
                else
                {
                    input[i][j]=0;
                }
            }
        }
        
        int room=1;
        vector<int> result;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(input[i][j]==0)
                {
                    roomSize=1;
                    input[i][j]=room;
                    func(room,i,j);
                    room++;
                    result.push_back(roomSize);
                }
            }
        }
        cout<<result.size()<<"\n";
        sort(result.begin(), result.end(), greater<int>());
        for(int i=0 ; i<result.size() ; i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
}
