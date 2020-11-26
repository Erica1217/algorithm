//
//  main.cpp
//  11057 오르막 수
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

int devide(int n)
{
    return n%10007;
}

int main()
{
    int n;
    cin>>n;
    int data[1100][20]={0,};
    for(int i=0 ; i<=9 ; i++)
    {
        data[1][i]=1;
    }
    
    for(int i=2 ; i<=n ; i++)
    {
        for(int j=0 ; j<=9 ; j++)
        {
            for(int k=j ; k<=9 ; k++)
            {
                data[i][k]= devide(data[i][k]+data[i-1][j]);
                
            }
        }
    }
    int sum=0;
    for(int i=0; i<=9 ; i++)
    {
        sum= devide(sum+data[n][i]);
    }
    cout<<sum;
}
