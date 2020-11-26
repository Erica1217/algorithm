//
//  main.cpp
//  14905 소수 4개의 합
//
//  Created by 김유진 on 2020/04/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int sosu[30000000]={0,};

int main()
{
    int n;
    cin>>n;
    for(int i=2 ; i<sqrt(1000000) ; i++)
    {
        for(int j=i*2 ; j<=100000 ; j++)
        {
            sosu[j]=1;
        }
    }
    
    int input;
    for(int i=0 ; i<n ; i++)
    {
        cin>>input;
        cout<<sosu[input]<<"\n";
    }
}
