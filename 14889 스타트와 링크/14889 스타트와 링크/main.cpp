//
//  main.cpp
//  14889 스타트와 링크
//
//  Created by 김유진 on 2020/01/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int N;
int data[30][30]={0,};
int check[30]={0,};

int result=999999999;

void func(int n,int start,int link)
{
    for(int i=0; i<N ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            int s = start + data[
            func(n+1,)
        }
    }
}

int main()
{
    
    scanf("%d",&N);
    
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    
    
}
