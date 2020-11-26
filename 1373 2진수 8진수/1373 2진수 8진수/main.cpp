//
//  main.cpp
//  1373 2진수 8진수
//
//  Created by 김유진 on 2020/07/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
int main()
{
    char data[1100000];
    int stack[1100000]={0,};
    int top=0;
    scanf("%s",data);
    int n= strlen(data);
    for(int i=n-1 ; i>=0 ; i-=3)
    {
        int v=0;
        int w=1;
        for(int j=0 ; j<3; j++)
        {
            if(i-j<0)
                break;
            v+=w*(data[i-j]-'0');
            w*=2;
            
        }
        stack[top++]=v;
    }
    for(int i=top-1 ; i>=0 ; i--)
    {
        printf("%d",stack[i]);
    }
}
