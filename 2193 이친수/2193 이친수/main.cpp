//
//  main.cpp
//  2193 이친수
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long data[100][5]={0,};
    data[1][0]=0;
    data[1][1]=1;
    for(int i=2 ; i<=n ; i++)
    {
        data[i][0]=data[i-1][1] + data[i-1][0];
        data[i][1]=data[i-1][0];
    }
    cout<<data[n][0]+data[n][1];
}
