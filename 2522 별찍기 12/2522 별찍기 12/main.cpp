//
//  main.cpp
//  2522 별찍기 12
//
//  Created by 김유진 on 05/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0 ; i<n; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            printf(" ");
        }
        
        for(int j=0 ; j<=i ; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=0 ; j<=i ; j++)
        {
            printf(" ");
        }
        for(int j=0 ; j<n-i-1 ; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
