//
//  main.cpp
//  1918 후위표기식
//
//  Created by 김유진 on 2020/09/24.
//  Copyright © 2020 김유진. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <map>
using namespace std;
int main()
{
    string data;
    map<char, int> m;
    m['+']=2;
    m['-']=2;
    m['*']=1;
    m['/']=1;
    m['(']=0;
    // +, -, *, /, (, )
    cin>>data;
    deque<char> stack;
    for(int i=0 ; i<data.size() ; i++)
    {
        if('A'<=data[i] && data[i]<='Z')
        {
            printf("%c",data[i]);
        }
        else if(data[i]=='(')
        {
            stack.push_back(data[i]);
        }
        else if(data[i]==')')
        {
            char a;
            do{
                a=stack.back();
                stack.pop_back();
                if(a=='(')
                {
                    break;
                }
                printf("%c",a);
            }while(true);
        }
        else
        {
            for(int j=stack.size()-1 ; j>=0 ; j--)
            {
                if(stack[j]=='(')
                {
                    break;
                }
                if(m.find(stack[j])->second <= m.find(data[i])->second)
                {
                    printf("%c",stack.back());
                    stack.pop_back();
                }
            }
            stack.push_back(data[i]);
        }
    }
    for(int i=stack.size()-1 ; i>=0 ; i--)
    {
        printf("%c",stack[i]);
    }
}


