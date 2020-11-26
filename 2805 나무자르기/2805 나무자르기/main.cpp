//
//  main.cpp
//  2805 나무자르기
//
//  Created by 김유진 on 27/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
unsigned long long data[1100000]={0,};
int main()
{
    unsigned long long N,M;
    scanf("%llu %llu",&N,&M);
    unsigned long long max=0;
    for(int i=0 ; i<N ; i++)
    {
        scanf("%llu",&data[i]);
        if(data[i]>max)
            max=data[i];
    }
    
    unsigned long long front=0;
    unsigned long long end=max;
    unsigned long long middle=(front+end)/2;
    unsigned long long result=0;
    while(front<=end)
    {
        unsigned long long log=0;
        for(int i=0 ; i<N ; i++)
        {
            if((long long)(data[i]-middle) > 0)
            {
                log+=(data[i]-middle);
            }
        }
        if(log >= M)
        {
            front=middle+1;
            result = result<middle ? middle : result;
        }
        else
        {
            end = middle-1;
        }
        middle = (front+end)/2;
    }
    printf("%llu",result);
}
