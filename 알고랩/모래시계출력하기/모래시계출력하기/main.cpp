//
//  main.cpp
//  모래시계출력하기
//
//  Created by 김유진 on 2020/03/30.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int a=0 ; a<t ;a++)
    {
        int n;
        cin>>n;
        for(int i=0 ; i<=n/2 ; i++)
        {
            for(int j=0 ; j<i ; j++)
            {
                cout<<'-';
            }
            
            for(int j=0 ; j<n/2-i; j++)
            {
                cout<<"*+";
            }
            cout<<"*";
            
            
            for(int j=0 ; j<i ; j++)
            {
                cout<<'-';
            }
            cout<<endl;
        }
        
        for(int i=1 ; i<=n/2 ; i++)
        {
            for(int j=0 ; j<n/2-i ; j++)
            {
                cout<<'-';
            }
            
            for(int j=0 ; j<i; j++)
            {
                cout<<"*+";
            }
            cout<<"*";
            
            
            for(int j=0 ; j<n/2-i ; j++)
            {
                cout<<'-';
            }
            cout<<endl;
        }
    }
}
