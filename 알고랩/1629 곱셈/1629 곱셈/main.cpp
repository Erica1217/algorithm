//
//  main.cpp
//  1629 곱셈
//
//  Created by 김유진 on 2020/04/10.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <cmath>
int main()
{
    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    long long sb = sqrt(b);
    long long result = 1;
    
    for(int i=1 ; i<=sb ; i++)
    {
        result = ((long long)(result*a))%c;
    }
    long long sr = result;
    for(long long i=sb ; i<b ; i+=sb)
    {
        result = ((long long)(sr*result))%c;
    }
    
    for(long long i=0 ; i<b%sb ; i++)
    {
        result = ((long long)(result*a))%c;
    }
    printf("%lld",result);
}

