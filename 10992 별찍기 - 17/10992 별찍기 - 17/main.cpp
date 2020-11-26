//
//  main.cpp
//  10992 별찍기 - 17
//
//  Created by 김유진 on 21/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    if(n==1)
    {
        cout<<"*";
        return 0;
    }
    
    for(int i=0 ; i<n-1 ; i++)
    {
        cout<<" ";
    }
    cout<<"*\n";
    
    for(int i=0 ; i<n-2 ; i++)
    {
        for(int j=0 ; j<n-2-i ; j++)
        {
            cout<<" ";
        }
        cout<<"*";
        for(int j=0 ; j<i*2+1 ; j++)
        {
            cout<<" ";
        }
        cout<<"*\n";
    }
    
    for(int i=0 ; i<n*2-1 ; i++)
    {
        cout<<"*";
    }
    
}
