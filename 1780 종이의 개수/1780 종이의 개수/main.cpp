//
//  main.cpp
//  1780 종이의 개수
//
//  Created by 김유진 on 2020/03/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[2200][2200]={0,};
int result[5]={0,};

void func(int num, int x, int y)
{
    if(num==1)
    {
        result[data[x][y]]++;
        return;
    }
    
    bool isSame=true;
    int a=data[x][y];
    for(int i=x ; i<x+num ; i++)
    {
        for(int j=y ; j<y+num ; j++)
        {
            if(data[i][j]!=a)
            {
                isSame=false;
                for(int k1=0 ; k1<num ; k1+=(num/3))
                {
                    for(int k2=0 ; k2<num ; k2+=(num/3))
                    {
                        func(num/3, x+k1, y+k2);
                    }
                }
                return;
            }
        }
    }
    result[data[x][y]]++;
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&data[i][j]);
            data[i][j]++;
        }
    }
    func(n,0,0);
    for(int i=0 ; i<3 ; i++)
    {
        printf("%d\n",result[i]);
    }
    
}
