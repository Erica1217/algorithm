//
//  main.cpp
//  17413 단어 뒤집기2
//
//  Created by 김유진 on 2020/07/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char stack[110000]={0,};
    string str;
    getline(cin,str);
    
    int n= str.size();
    int top=0;
    bool check=false;
    for(int i=0 ; i<n ; i++)
    {
        if(str[i]=='<')
        {
            check=true;
            for(int j=top-1 ; j>=0 ; j--)
            {
                printf("%c",stack[j]);
            }
            top=0;
            printf("<");
        }
        else if(str[i]=='>')
        {
            printf(">");
            check=false;
        }
        else if(check)
        {
            printf("%c",str[i]);
        }
        else if(str[i]==' ')
        {
            for(int j=top-1 ; j>=0 ; j--)
            {
                printf("%c",stack[j]);
            }
            printf(" ");
            top=0;
        }
        else
        {
            stack[top++]=str[i];
        }
    }
    for(int j=top-1 ; j>=0 ; j--)
    {
        printf("%c",stack[j]);
    }
}
