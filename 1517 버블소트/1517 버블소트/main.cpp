//
//  main.cpp
//  1517 버블소트
//
//  Created by 김유진 on 16/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    long long data[500010]={0,};
    int dap=0;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%lld",&data[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(data[j] > data[j+1])
            {
                long long t=data[j];
                data[j]=data[j+1];
                data[j+1]=t;
                dap++;
            }
        }
    }
    printf("%d",dap);
}
