//
//  main.cpp
//  9660 돌게임 6
//
//  Created by 김유진 on 2020/04/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    long long n;
    scanf("%lld",&n);
    int num=0;
    for(int i=1 ; i<=n ; i++)
    {
        if(i%7==0||i%7==2)
        {
//            printf("%d\n",i);
            num++;
        }
//        printf("%d ",i);
//        printf(i%7==0||i%7==2?"2\n":"1\n");
    }
//    printf(n%7==0||n%7==2?"CY":"SK");
    printf("%d\n",num);
}
