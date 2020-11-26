//
//  main.cpp
//  14501 퇴사
//
//  Created by 김유진 on 2020/01/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int N;
    int T[1010]={0,};
    int P[1010]={0,};
    int data[1010]={0,};
    
    scanf("%d",&N);
    for(int i=0 ; i<N ; i++)
    {
        scanf("%d %d",&T[i], &P[i]);
    }
    
    for(int i=0 ; i<N ; i++)
    {
        for(int j=i+T[i] ; j<=N ; j++)
        {
            if(data[j] < data[i] + P[i])
            {
                data[j] = data[i] + P[i];
            }
            
        }
        
    }
//    printf("\n");
//
//    for(int i=0 ; i<N ; i++)
//    {
//        printf("%2d ",data[i]);
//    }
    
    int result = data[N];
    printf("%d", result);
}
