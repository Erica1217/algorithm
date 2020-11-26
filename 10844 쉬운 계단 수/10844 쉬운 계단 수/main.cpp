//
//  main.cpp
//  10844 쉬운 계단 수
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int devide(int n)
{
    return n%1000000000;
}

int main()
{
    int n;
    cin>>n;
    int data[110][20]={0,};
    
    for(int i=1;i<=9; i++)
    {
        data[1][i]=1;
    }
    
    for(int i=2; i<=n ; i++)
    {
        for(int j=1; j<=8 ; j++)
        {
            data[i][j-1]=devide(data[i][j-1]+data[i-1][j]);
            data[i][j+1]=devide(data[i][j+1]+data[i-1][j]);
        }
        data[i][1] = devide(data[i][1]+data[i-1][0]);
        data[i][8] = devide(data[i][8]+data[i-1][9]);
    }
    
    int sum=0;
    for(int i=0 ; i<=9 ; i++)
    {
        sum= devide(sum+data[n][i]);
    }
    cout<<sum;
}
