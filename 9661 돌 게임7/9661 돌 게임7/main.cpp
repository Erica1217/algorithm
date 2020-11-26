//
//  main.cpp
//  9661 돌 게임7
//
//  Created by 김유진 on 2020/04/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    long long n;
    scanf("%lld",&n);
    printf(n%5==2||n%5==0?"CY":"SK");
    int num=0;
    for(int i=1 ; i<=n ; i++)
    {
        if(i%5==2 || i%5==0)
        {
            num++;
        }
    }
    printf("%d",num);
}
