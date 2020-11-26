//
//  main.cpp
//  1550 16진수
//
//  Created by 김유진 on 12/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
#include <string>
int main()
{
    char data[10];
    int sum=0;
    scanf("%s",data);
    int length = strlen(data);
    int data2[10];
    
    for(int i=0 ; i<length ; i++)
    {
        if('A' <= data[i] && data[i]<='F')
        {
            data2[i]=data[i]-55;
        }
        else
        {
            data2[i]=data[i]-'0';
        }
    }
    for(int  i=0 ; i<length ; i++)
    {
        for(int j=0 ; j<i ; j++)
        {
            data2[j]*=16;
        }
    }
    for(int i=0 ; i<length ; i++)
    {
        sum+=data2[i];
    }
    printf("%d",sum);
    
}
