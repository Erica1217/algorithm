//
//  main.cpp
//  10996 별 찍기-21
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
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(j%2==0)
                cout<<"*";
            else
                cout<<" ";
        }
        printf("\n");
        
        for(int j=0 ; j<n ; j++)
        {
            if(j%2==1)
                cout<<"*";
            else
                cout<<" ";
        }
        printf("\n");
    }
}
