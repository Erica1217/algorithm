//
//  main.cpp
//  소마2차 1
//
//  Created by 김유진 on 2020/04/26.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n;
    int input[110000]={0,};
    long long data[110000]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    data[0]=input[0];
    long long result=input[0];
    for(int i=1 ; i<n ; i++)
    {
        data[i] = input[i]>input[i]+data[i-1] ? input[i]:input[i]+data[i-1];
        result = result<data[i]?data[i]:result;
    }
    printf("%lld\n",result);
}
