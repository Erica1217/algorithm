//
//  main.cpp
//  16637 괄호 추가하기
//
//  Created by 김유진 on 2020/04/05.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
char input[25]={0,};
int check[25]={0,};
int result=-999999999;

int calculate(char oper, int a, int b)
{
    switch (oper) {
        case '*':
            return a*b;
        case '+':
            return a+b;
        case '-':
            return a-b;
    }
    return 0;
}

void func(int num, int data)
{
//    printf("*%d %d\n",num,data);
    if(num>=n)
    {
        if(result<data)
        {
            result =data;
        }
        return;
    }

    if(check[num]==0)
    {
        check[num]=1;
        
        int d = calculate(num-1>=0 ? input[num-1]:'+',data,input[num]-'0');
        func(num+2,d);
        check[num]=0;
     
    }
    if(check[num]==0 && check[num+2]==0 &&num+2<n)
    {
        check[num]=1;
        check[num+2]=1;
        
        int c = calculate(input[num+1],input[num]-'0', input[num+2]-'0');
        int d = calculate(num-1>=0 ? input[num-1]:'+',data,c);
        func(num+4,d);
        
        check[num]=0;
        check[num+2]=0;
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%s",input);
    
    func(0,0);
    printf("%d",result);
}
