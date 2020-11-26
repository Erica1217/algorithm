//
//  main.cpp
//  14754 Pizza Boxes
//
//  Created by 김유진 on 23/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

int data[1100][1100]={0,};
int check[1100][1100]={0,};

int main()
{
    int n,m;
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
        int horizontal_index=0;
        int h_max=0;
        for(int j=0 ; j<m ; j++)
        {
            if(data[i][j]>h_max)
            {
                h_max=data[i][j];
                horizontal_index=j;
            }
        }
        check[i][horizontal_index]=1;
    }
    
    for(int i=0 ; i<m ; i++)
    {
        int vertical_index=0;
        int v_max=0;
        for(int j=0 ; j<n ; j++)
        {
            if(data[j][i]>v_max)
            {
                v_max =data[j][i];
                vertical_index=j;
            }
        }
        check[vertical_index][i]=1;
    }
    
    long long int sum=0;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(check[i][j] == 0)
            {
                sum+=data[i][j];
            }
        }
    }
    cout<<sum;
}
