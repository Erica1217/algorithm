//
//  main.cpp
//  삼각형의종류2
//
//  Created by 김유진 on 2020/04/08.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int t;
    int loc[4][4];
    cin>>t;
    for(int k=0 ; k<t ; k++)
    {
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<2 ; j++)
            {
                cin>>loc[i][j];
            }
        }
        vector<int> d;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=i+1 ; j<3 ; j++)
            {
                int a = (loc[i][0]-loc[j][0])*(loc[i][0]-loc[j][0]);
                int b = (loc[i][1]-loc[j][1])*(loc[i][1]-loc[j][1]);
                d.push_back(a+b);
            }
        }
        sort(d.begin(), d.end());
//        printf("[%d %d %d]\n",d[0],d[1],d[2]);
        if(sqrt(d[0])+sqrt(d[1])<=sqrt(d[2]))
        {
            cout<<"0\n";
        }
        else if(d[0]+d[1]==d[2])
        {
            cout<<"1\n";
        }
        else if(d[0]+d[1]<d[2])
        {
            cout<<"2\n";
        }
        else if(d[0]+d[1]>d[2])
        {
            cout<<"3\n";
        }
    }
}
