//
//  main.cpp
//  1306 달려라 홍준
//
//  Created by 김유진 on 2020/08/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int data[1100000]={0,};
    for(int i=0; i<n; i ++)
    {
        scanf("%d",&data[i]);
    }
    
    int max=0;
    int maxIdx=0;
    int sMax=0;
    int sMaxIdx=0;
    for(int i=0 ; i<(m-1)*2+1 ; i++)
    {
        if(max<=data[i])
        {
            max = data[i];
            maxIdx = i;
        }
        else if(sMax <= data[i])
        {
            sMax = data[i];
            sMaxIdx = i;
        }
    }
    printf("%d ",max);
    
    for(int i=m; i<=n-m ; i++)
    {
//        printf("%d %d [%d]\n",maxIdx, i-m,i);
        printf("[%d] %d %d\n",i, max, sMax);
        if(maxIdx == i-m)
        {
            max = sMax;
            maxIdx = sMaxIdx;
            sMax=0;
            sMaxIdx=0;
        }
        
        if(max<=data[i+m-1])
        {
            max = data[i+m-1];
            maxIdx = i+m-1;
        }
        else if(sMax <= data[i+m-1])
        {
            sMax = data[i+m-1];
            sMaxIdx = i+m-1;
        }
        printf("%d ",max);
    }
}
