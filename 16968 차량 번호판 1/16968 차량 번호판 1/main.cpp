//
//  main.cpp
//  16968 차량 번호판 1
//
//  Created by 김유진 on 2020/03/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
int main()
{
    char input[10];
    int n;
    scanf("%s",input);
    n=strlen(input);
    int result = input[0]=='c'?26:10;
    
    int a;
    for(int i=1 ; i<n ; i++)
    {
        a =input[i]=='c'?26:10;
        if(input[i] == input[i-1])
        {
            a--;
        }
        result*=a;
    }
    printf("%d",result);
}
