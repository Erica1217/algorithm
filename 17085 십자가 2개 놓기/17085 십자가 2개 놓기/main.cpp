//
//  main.cpp
//  17085 십자가 2개 놓기
//
//  Created by 김유진 on 2020/03/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

int dx[5] = {0,0,-1,1};
int dy[5] = {-1,1,0,0};
int n,m;
char input[20][20];

struct type{
    int x,y,size;
};

void changeValue(type t, char value)
{
    for(int i=0 ; i<=t.size ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            int X = dx[j]*i + t.x;
            int Y = dy[j]*i + t.y;
            input[X][Y]=value;
        }
    }

}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0 ;i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    vector<type> data;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(input[i][j]=='#')
            {
                int size=0;
                bool possible=true;
                while(possible)
                {
                    size++;
                    for(int k=0 ; k<4 ; k++)
                    {
                        int X = dx[k]*size+i;
                        int Y = dy[k]*size+j;
                        if(X<0 || X>=n || Y<0 || Y>=m || input[X][Y]=='.')
                        {
                            possible = false;
                        }
                           
                    }
                }
                size--;
                type t;
                t.x=i;
                t.y=j;
                t.size = size;
                data.push_back(t);
            }
        }
    }
    
//    for(int i=0 ; i<data.size() ; i++)
//    {
//        printf("%d %d\n",data[i].x,data[i].y);
//    }
//
    int result=0;
    for(int i=0 ; i<data.size() ;i++)
    {
        changeValue(data[i], '0');
        for(int j=i+1 ; j<data.size() ; j++)
        {
            bool isPossible=true;
            for(int k=0 ; k<=data[j].size ; k++)
            {
                for(int q=0 ; q<4 ; q++)
                {
                    int X = data[j].x + (dx[q]*k);
                    int Y = data[j].y + (dy[q]*k);
                    if(input[X][Y]!='#')
                    {
                        isPossible = false;
                    }
                }
            }
            if(isPossible)
            {
                int a = ((data[i].size*4)+1)*((data[j].size*4)+1);
                if(a>result)
                {
                    result = a;
                }
            }
        }
        changeValue(data[i], '#');
    }
    printf("%d",result);
}

