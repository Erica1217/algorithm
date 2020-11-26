//
//  main.cpp
//  1748 수 이어쓰기 1
//
//  Created by 김유진 on 2020/02/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    
    long long result=0;
    
    int digit=1;
    if(n<10)
    {
        printf("%d",n);
        return 0;
    }
    
    for(int i=1 ;  ; i++)
    {
        result+=digit*9*i;
        digit*=10;
        if(n<(digit*10)-1)
        {
            result+=(i+1)*(n-(digit-1));
            break;
        }
    }
    printf("%lld\n",result);
}
