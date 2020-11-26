//
//  main.cpp
//  행렬곱셈
//
//  Created by 김유진 on 2020/04/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    int r,s,t;
    while(testcase--)
    {
        cin>>r>>s>>t;
        int a[110][110]={0,};
        int b[110][110]={0,};
        
        for(int i=0 ; i<r; i++)
        {
            for(int j=0 ; j<s ; j++)
            {
                cin>>a[i][j];
            }
        }
        
        for(int i=0 ; i<s; i++)
        {
            for(int j=0 ; j<t; j++)
            {
                cin>>b[i][j];
            }
        }
        
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<t ; j++)
            {
                int sum=0;
                for(int k=0 ; k<s ; k++)
                {
                    sum+=a[i][k]*b[k][j];
                }
                cout<<sum<<" ";
            }
            cout<<"\n";
        }
    }
}
