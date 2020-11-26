//
//  main.cpp
//  2740 행렬곱셈
//
//  Created by 김유진 on 2020/04/10.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,m;
    int data[110][110]={0,};
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<M ; j++)
        {
            scanf("%d",data[i][j])
        }
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            
        }
    }
}
