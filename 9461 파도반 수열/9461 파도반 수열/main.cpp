//
//  main.cpp
//  9461 파도반 수열
//
//  Created by 김유진 on 09/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int T;
    int input[110]={0,};
    unsigned long long int data[110]={0,};
    int max=0;
    scanf("%d",&T);
    for(int a=0 ; a<T ; a++)
    {
        scanf("%d",&input[a]);
        if(max < input[a])
            max = input[a];
    }
    
    data[1]=1;
    data[2]=1;
    data[3]=1;
    for(int i=4 ; i<=max ; i++)
    {
        data[i] = data[i-2] + data[i-3];
    }
    
    for(int i=0 ; i<T ; i++)
    {
        printf("%lld\n",data[input[i]]);
    }
}
