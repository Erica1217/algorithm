//
//  main.cpp
//  1934 최소공배수
//
//  Created by 김유진 on 2020/04/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a<b)
        {
            int q=a;
            a=b;
            b=q;
        }
        int m=1;
        for(int i=b ; i>=1 ; i--)
        {
            if(a%i==0 && b%i==0)
            {
                m=i;
                break;
            }
        }
        printf("%d\n",a*b/m);
    }
}
