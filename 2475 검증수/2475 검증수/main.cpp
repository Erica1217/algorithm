//
//  main.cpp
//  2475 검증수
//
//  Created by 김유진 on 16/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    int sum=0;
    for(int i=0 ; i<5 ; i++)
    {
        scanf("%d",&n);
        sum+=(n*n);
    }
    printf("%d",sum%10);
}
