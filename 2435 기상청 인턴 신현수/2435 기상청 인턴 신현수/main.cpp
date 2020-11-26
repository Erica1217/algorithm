//
//  main.cpp
//  2435 기상청 인턴 신현수
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,k;
    int data[1010]={0,};
    scanf("%d %d",&n,&k);
    
    int result=0;
    int sum=0;
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    for(int i=0 ; i<k ; i++)
    {
        sum+=data[i];
    }
    result = sum;
    
    for(int i=1 ; i<= n-k ; i++)
    {
        sum-=data[i-1];
        sum+=data[i+k-1];
        if(result < sum)
        {
            result = sum;
        }
        printf("%d %d %d\n",i,sum, result);
    }
    printf("%d",result);
}
