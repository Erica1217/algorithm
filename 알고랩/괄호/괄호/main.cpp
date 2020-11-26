//
//  main.cpp
//  괄호
//
//  Created by 김유진 on 2020/04/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string arr;
    while(t--)
    {
        cin>>arr;
        int result=1;
        char stack[110]={0,};
        char open[5]={'(','{','['};
        char close[5]={')','}',']'};
        int top=0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            if(arr[i]=='(' || arr[i]=='{' || arr[i]=='[')
            {
                stack[top++]=arr[i];
            }
            else
            {
                bool isOk=false;
                for(int j=0 ; j<3 ; j++)
                {
                    if(top-1>=0 && arr[i]==close[j] && stack[top-1]==open[j])
                    {
                        top--;
                        isOk=true;
                        break;
                    }
                }
                if(!isOk)
                {
                    result=0;
                    break;
                }
            }
        }
        if(top!=0)
        {
            result=0;
        }
        cout<<result<<"\n";
    }
}
