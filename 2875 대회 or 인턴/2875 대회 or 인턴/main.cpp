//
//  main.cpp
//  2875 대회 or 인턴
//
//  Created by 김유진 on 2020/03/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    if(n==0 || m==0)
    {
        printf("0");
        return 0;
    }
    if(n>m*2)
    {
        int a=n-(m*2);
        k-=a;
        if(k<=0)
        {
            printf("%d",m);
            return 0;
        }
        n-=a;
    }
    else if(n<m*2)
    {
        int a=m-(n/2);
        k-=a;
        if(k<=0)
        {
            printf("%d",n/2);
            return 0;
        }
        m-=a;
    }
    int a = k/3 + (k%3==0?0:1);
    printf("%d",m-a<0?0:m-a);
}
