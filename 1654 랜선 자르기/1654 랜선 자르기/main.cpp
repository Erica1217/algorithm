//
//  main.cpp
//  1654 랜선 자르기
//
//  Created by 김유진 on 2020/03/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    long long k,n;
    scanf("%lld %lld",&k,&n);
    long long data[11000]={0,};
    for(int i=0 ; i<k ; i++)
    {
        scanf("%lld",&data[i]);
    }
    
    long long max=0;
    for(int i=0 ; i<k ; i++)
    {
        if(max<data[i])
            max=data[i];
    }
    
    long long result=0;
    long long left=1;
    long long right=max;
    long long mid = (left+right)/2;
    while(left<=right)
    {
        mid = (left+right)/2;
//        printf("%d %d\n",left,right);;
        long long a=0;
        for(int i=0 ; i<k ; i++)
        {
            a+=(data[i]/mid);
        }
        
        
        if(n>a)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
            if(result<mid)
            {
                result=mid;
            }
        }
    }
    printf("%lld",result);
}
