//
//  main.cpp
//  1978 소수 찾기
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <math.h>

int main()
{
    int n;
    int data[110];
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    int result=0;
    
    for(int i=0; i<n ; i++)
    {
        if(data[i]<2) continue;
        
        bool isSosu = true;
        for(int j=2 ; j<=sqrt(data[i]) ; j++)
        {
            if(data[i]%j==0)
            {
                isSosu = false;
                break;
            }
        }
        
        if(isSosu)
        {
            result++;
        }
    }
    printf("%d",result);
}
