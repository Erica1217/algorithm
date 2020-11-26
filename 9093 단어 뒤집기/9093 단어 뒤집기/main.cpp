//
//  main.cpp
//  9093 단어 뒤집기
//
//  Created by 김유진 on 2020/07/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        string data;
        getline(cin,data);
        int len = data.size();
        int t=0;
        for(int i=0 ; i<len ; i++)
        {
            if(data[i]==' ')
            {
                for(int j=i-1 ; j>=i-t ; j--)
                {
                    printf("%c",data[j]);
                }
                printf(" ");
                t=0;
            }
            else
            {
                t++;
            }
        }
        for(int i=len-1 ; i>=len-t ; i--)
        {
            printf("%c",data[i]);
        }
        printf("\n");
    }
}
