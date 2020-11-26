//
//  main.cpp
//  동전 배분
//
//  Created by 김유진 on 2020/03/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int T;
    scanf("%d",&T);
    int a,b,c,n;
    for(int i=0 ; i<T ; i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&n);
        int sum=a+b+c+n;
        if(sum%3!=0)
        {
            printf("NO\n");
            continue;
        }
        int d= sum/3;
        if(a<=d && b<=d && c<=d)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
