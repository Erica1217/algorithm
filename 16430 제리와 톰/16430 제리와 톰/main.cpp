//
//  main.cpp
//  16430 제리와 톰
//
//  Created by 김유진 on 13/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    A=B-A;
    
    for(int i=2 ; i<=9 ; i++)
    {
        if(A%i==0 && B%i==0)
        {
            A/=i;
            B/=i;
        }
    }
    printf("%d %d",A,B);
}

