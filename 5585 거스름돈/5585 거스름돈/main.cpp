//
//  main.cpp
//  5585 거스름돈
//
//  Created by 김유진 on 13/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    int data[10]={500,100,50,10,5,1};
    int coin=0;
    scanf("%d",&n);
    n=1000-n;
    
    for(int i=0 ; i<6 ; i++)
    {
        coin+=(n/data[i]);
        n%=data[i];
    }
    printf("%d",coin);
}
