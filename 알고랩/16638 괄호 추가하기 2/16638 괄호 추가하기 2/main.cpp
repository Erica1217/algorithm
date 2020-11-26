//
//  main.cpp
//  16638 괄호 추가하기 2
//
//  Created by 김유진 on 2020/03/31.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <limits.h>

const int PLUS=10000;
const int MINUS=20000;
const int MULTIPLY=30000;
int check[25]={0,};
int n;
int data[25];
char input[25];
long long result=LLONG_MIN;

int calculate(int a,int b, char oper)
{
    switch (oper) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        default:
            break;
    }
    return 0;
}

void func(int num,int top)
{
    printf("*%d %d\n",num,top);
    if(num>=n)
    {
        for(int i=1 ; i<top ; i++)
        {
            if(data[i]==MULTIPLY)
            {
                int a = data[i-1]*data[i+1];
                data[i-1]=a;
                data[i]=a;
                data[i+1]=a;
            }
            printf("%d ",data[i]);
        }
        printf("\n\n----\n");
        
        int r=data[0];
        for(int i=1 ; i<top ; i+=2)
        {
            if(data[i]==PLUS)
            {
                r+=data[i+1];
            }
            if(data[i]==MINUS)
            {
                r-=data[i+1];
            }
        }
        
        if(r>result)
        {
            result=r;
        }
        return;
    }

    if(check[num]==0)
    {
        check[num]=1;
        data[top]=input[num]-'0';
        if(top+1<n)
        {
            data[top+1]=input[num+1]=='+'?PLUS:input[num+1]=='*'?MULTIPLY:MINUS;
            func(num+2,top+2);
        }
        else
        {
            func(num+2,top+1);
        }
        
        check[num]=0;
    }
    
    if(check[num]==0 && check[num+2]==0)
    {
        check[num]=1;
        check[num+2]=1;
        data[top]=calculate(input[num]-'0',input[num+2]-'0',input[num-1]);
        if(num+3<n)
        {
            data[top+1]=input[num+3]=='+'?PLUS:input[num+3]=='*'?MULTIPLY:MINUS;
            func(num+4,top+1);
        }
        else
        {
            func(num+4,top+2);
        }
        check[num]=0;
        check[num+2]=0;
    }
}

using namespace std;
int main()
{
    scanf("%d",&n);
    scanf("%s",input);
    
    func(0,0);
    printf("%lld",result);
}
