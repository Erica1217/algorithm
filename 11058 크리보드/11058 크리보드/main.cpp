//
//  main.cpp
//  11058 크리보드
//
//  Created by 김유진 on 02/06/2019.
//  Copyright © 2019 김유진. All rights reserved.
//
#include <stdio.h>
int main()
{
    freopen("/Users/kim-yujin/Documents/알고리즘/11058 크리보드/11058 크리보드/input.txt","r",stdin);
    
    int n;
    long long data[110]={0,};
    scanf("%d",&n);
    data[0]=0;
    for(int i=1; i<=n; i++)
    {
        data[i] = data[i-1]+1;
        for(int j=i-1 ; j>=3 ; j--)
        {
           long long a = data[i-j] * (j-1);
            if(data[i] < a){
                data[i]=a;
            }
        }
    }
    
    printf("%lld",data[n]);
}
