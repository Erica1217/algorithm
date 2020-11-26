//
//  main.cpp
//  2580 스도쿠
//
//  Created by 김유진 on 2020/01/31.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int data[20][20]={0,};

int vertiCheck[20][20]={0,};
int horiCheck[20][20]={0,};
int check3x3[20][20][20]={0,};
bool hasRseult=false;
vector<pair<int ,int>> empty;

int cnt0=0;

void func(int n)
{
    if(n == empty.size() && !hasRseult)
    {
        hasRseult = true;
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                printf("%d ",data[i][j]);
            }
            printf("\n");
        }
        return;
    }
    
    if(hasRseult)
    {
        return;
    }
    
    int x = empty[n].first;
    int y = empty[n].second;
    for(int i=1 ; i<=9 ; i++)
    {
        if(vertiCheck[x][i]==0 &&
           horiCheck[y][i]==0 &&
           check3x3[x/3][y/3][i]==0)
        {
            vertiCheck[x][i]=1;
            horiCheck[y][i]=1;
            check3x3[x/3][y/3][i]=1;
            data[x][y]=i;

            func(n+1);

            data[x][y]=0;
            vertiCheck[x][i]=0;
            horiCheck[y][i]=0;
            check3x3[x/3][y/3][i]=0;
        }
    }
}

int main()
{
    for(int i=0 ; i<9 ; i++)
    {
        for(int j=0 ; j<9 ; j++)
        {
            scanf("%d",&data[i][j]);
            int a=data[i][j];
            vertiCheck[i][a]=1;
            horiCheck[j][a]=1;
            check3x3[i/3][j/3][a]=1;
            
            if(a==0)
            {
                empty.push_back(make_pair(i,j));
                cnt0++;
            }
        }
    }
    func(0);
}
