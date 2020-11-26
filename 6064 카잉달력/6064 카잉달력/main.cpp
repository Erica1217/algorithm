//
//  main.cpp
//  6064 카잉달력
//
//  Created by 김유진 on 2020/02/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int main()
{
    int T;
    scanf("%d",&T);
    int m,n,x,y;
    for(int a=0 ; a<T ; a++)
    {
        scanf("%d %d %d %d",&m,&n,&x,&y);
        int lcd = m*n/gcd(m,n);
        int num=0;
        for(int i=0 ;  ; i++)
        {
            num = i*m+x;
            
            if(num > lcd)
            {
                printf("-1\n");
                break;
            }
            
            if((num-y)%n==0)
            {
                printf("%d\n",num);
                break;
            }
        }
    }
}
