//
//  main.cpp
//  행렬곱셈
//
//  Created by 김유진 on 2020/04/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,m;
    int data[110][110]={0,};
    int data2[110][110]={0,};
    while(t--)
    {
        cin>>n>>m;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                cin>>data[i][j];
            }
        }
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                cin>>data2[i][j];
            }
        }
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                cout<<(data[i][j]+data2[i][j])<<" ";
            }
            cout<<"\n";
        }
    }
}
