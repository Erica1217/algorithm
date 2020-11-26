//
//  main.cpp
//  2167 2차원 배열의 합
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <stdio.h>

int main()
{
    int N,M,K;
    int x1,y1,x2,y2;
    int data[400][400]={0,};
    
    scanf("%d %d",&N,&M);
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<M ; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    scanf("%d",&K);
    for(int i=0 ; i<K ; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1--;y1--;x2--;y2--;
        
        int sum=0;
        for(int j=x1 ; j<=x2 ; j++)
        {
            for(int k=y1 ; k<=y2 ; k++)
            {
                sum+=data[j][k];
//                printf("*%d\n",sum);
            }
        }
        printf("%d\n",sum);
    }
}
