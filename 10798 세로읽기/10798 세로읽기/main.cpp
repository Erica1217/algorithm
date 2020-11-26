//
//  main.cpp
//  10798 세로읽기
//
//  Created by 김유진 on 16/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>

int main()
{
    char data[50][50]={0,};
    for(int i=0 ; i<5 ; i++)
    {
        scanf("%s",data[i]);
    }
    
    for(int i=0; i<15 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            if(data[j][i]!='\0')
                printf("%c",data[j][i]);
        }
    }
}
