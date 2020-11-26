//
//  main.cpp
//  1106 호텔
//
//  Created by 김유진 on 09/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int C,N;
    int cost[25];
    int person[25];
    int data[101000]={0,};
    scanf("%d %d",&C,&N);
    for(int i=0 ; i<N ; i++)
    {
        scanf("%d %d",&cost[i], &person[i]);
    }
    
    for(int i=0 ; i<N ; i++)
    {
        for(int j=cost[i] ; j<=100000 ; j++)
        {
            if((j==cost[i] || data[j-cost[i]]!=0) && (data[j]==0 || data[j]<data[j-cost[i]]+person[i]))
            {
                data[j] = data[j-cost[i]]+person[i];
            }
        }
    }
    
    for(int i=1 ; i<=100000 ; i++)
    {
        printf("%d %d\n",i, data[i]);
        if(data[i]>=C)
        {
            printf("%d",i);
            return 0;
        }
    }
}
