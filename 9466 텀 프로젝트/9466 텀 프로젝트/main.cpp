//
//  main.cpp
//  9466 텀 프로젝트
//
//  Created by 김유진 on 2020/08/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
int data[110000]={0,};
int check[110000]={0,};
int cnt=0;

void find(int num, int start)
{
    if(check[start]==0)
    {
        check[start]=num;
        find(num+1,data[start]);
        check[start]=-1;
    }
    else if(check[start]==-1)
    {
        return;
    }
    else
    {
        cnt+=num-check[start];
        return;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt=0;
        for(int i=1 ; i<=n ; i++)
        {
            scanf("%d",&data[i]);
            check[i]=0;
        }
        
        for(int i=1 ; i<=n ; i++)
        {
            if(check[i]==0)
            {
                find(1,i);
                check[i]=-1;
            }
        }
        printf("%d\n",n-cnt);
    }
}
