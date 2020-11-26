//
//  main.cpp
//  삼각형의 종류
//
//  Created by 김유진 on 2020/04/08.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    int a,b,c;
    cin>>t;
    for(int i=0 ; i<t ;i++)
    {
        cin>>a>>b>>c;
        if((a+b)<=c)
        {
            cout<<"0\n";
        }
        else if(a==b && b==c)
        {
            cout<<"1\n";
        }
        else if((a*a)+(b*b)==(c*c))
        {
            cout<<"2\n";
        }
        else if(a==b || b==c)
        {
            cout<<"3\n";
        }
        else
        {
            cout<<"4\n";
        }
    }
}
