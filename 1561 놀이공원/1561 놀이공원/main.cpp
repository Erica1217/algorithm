//
//  main.cpp
//  1561 놀이공원
//
//  Created by 김유진 on 29/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int N,M;
int main()
{
    scanf("%d %d",&N,&M);
    int data[11000]={0};
    long long max=0;
    for(int i=0 ; i<M ; i++)
    {
        scanf("%d",&data[i]);
        if(max<data[i])
            max=data[i];
    }
    
    long long front=0;
    long long end=(long long)(max*N);
    long long mid=(front+end)/2;
    long long midCnt=0;
    long long m=(long long)(max*N*M);

    while(front<=end)
    {
        long long cnt=M;
        for(int i=0; i<M ;i++)
        {
            cnt+=(mid/data[i]);
        }
        
        if(cnt >= N)
        {
            end=mid-1;
            if(mid < m)
            {
                m=mid;
                midCnt=cnt;
            }
        }
        else
        {
            front=mid+1;
        }
        mid=(front+end)/2;
    }
    long long cnt = midCnt;
    int a=0;

//    printf("**%lld %d %lld\n",cnt,N,m);
    for(int i=M-1 ; i>=0 ; i--)
    {
        if(m%data[i]==0)
        {
            a++;
        }

        if(a==cnt-N+1)
        {
            printf("%d",i+1);
            break;
        }
    }
}
