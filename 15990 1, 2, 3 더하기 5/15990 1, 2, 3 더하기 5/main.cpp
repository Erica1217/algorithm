//
//  main.cpp
//  15990 1, 2, 3 더하기 5
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//


#include <iostream>
using namespace std;
int main()
{
    int n;
    int input[11000]={0,};
    int data[110000][5]={0,};
    int max=0;
    
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        cin>>input[i];
        if(input[i]>max)
            max=input[i];
    }
    data[1][1]=1;
    data[2][2]=1;
    
    data[3][1]=1;
    data[3][2]=1;
    data[3][3]=1;
    for(int i=4 ; i<=max ; i++)
    {
        data[i][1]=(data[i-1][2] + data[i-1][3])%1000000009;
        data[i][2]=(data[i-2][1] + data[i-2][3])%1000000009;
        data[i][3]=(data[i-3][1] + data[i-3][2])%1000000009;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        int sum=0;
        for(int j=1;j<=3;j++)
        {
            sum=(sum+data[input[i]][j])%1000000009;
        }
        cout<<sum<<endl;
    }
}
