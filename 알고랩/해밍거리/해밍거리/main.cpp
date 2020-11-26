//
//  main.cpp
//  해밍거리
//
//  Created by 김유진 on 2020/05/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

int getHaming(int n)
{
    int result=0;
    while(n!=0)
    {
        if(n%2==1)
        {
            result++;
        }
        n/=2;
    }
    return result;
}

int main()
{
    unsigned int t;
    cin>>t;
    
    unsigned int m,n;
    while(t--)
    {
        cin>>m>>n;
        cout<<getHaming(m)<<" ";
        cout<<getHaming(n)<<" ";
        cout<<getHaming(m^n)<<endl;
    }
}
