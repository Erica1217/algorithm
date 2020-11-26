//
//  main.cpp
//  10990 별찍기 15
//
//  Created by 김유진 on 05/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0 ; i<n-1 ; i++)
    {
        printf(" ");
    }
    printf("*\n");
    for(int i=0 ; i<n-1; i++)
    {
        for(int j=0 ; j<n-2-i ; j++)
        {
            printf(" ");
        }
        printf("*");
        for(int j=0 ; j<i*2+1 ; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
}
