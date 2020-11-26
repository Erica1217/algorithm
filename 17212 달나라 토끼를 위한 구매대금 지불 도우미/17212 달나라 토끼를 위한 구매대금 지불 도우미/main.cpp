//
//  main.cpp
//  17212 달나라 토끼를 위한 구매대금 지불 도우미
//
//  Created by 김유진 on 09/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n;
    int coin[5] = {1,2,5,7};
    int data[100100]={0,};
    
    scanf("%d",&n);

    for(int i=0 ; i<4 ; i++)
    {
        data[coin[i]]=1;
        for(int j=coin[i] ; j<=n ; j++)
        {
            if((data[j]>data[j-coin[i]]+1 || data[j]==0) && data[j-coin[i]]!=0)
            {
                data[j] = data[j-coin[i]]+1;
            }
        }
    }
    
//    for(int i=0 ; i<=n ; i++)
//    {
//        printf("%d %d\n",i,data[i]);
//    }
    printf("%d",data[n]);
}
