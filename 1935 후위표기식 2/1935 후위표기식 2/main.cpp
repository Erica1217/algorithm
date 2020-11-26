//
//  main.cpp
//  1935 후위표기식 2
//
//  Created by 김유진 on 2020/09/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    string str;
    int data[110]={0,};
    deque<double> stack;
    cin>>n;
    cin>>str;
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    for(int i=0 ; i<str.size() ; i++)
    {
        if('A'<=str[i] && str[i]<='Z')
        {
            stack.push_back(data[str[i]-'A']);
        }
        else
        {
            double a=stack.back();
            stack.pop_back();
            double b=stack.back();
            stack.pop_back();

            double result=0;
            switch (str[i]) {
                case '+':
                    result = a+b;
                    break;
                case '-':
                    result=b-a;
                    break;
                case '*':
                    result=b*a;
                    break;
                case '/':
                    result=b/a;
                    break;
            }
            stack.push_back(result);
        }
    }
    printf("%.2f",stack.back());
}
