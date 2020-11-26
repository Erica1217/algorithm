//
//  main.cpp
//  3040 백설 공주와 일곱 난쟁이
//
//  Created by 김유진 on 16/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int data[100]={0,};
    int sum=0;
    int n=9;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
        sum+=data[i];
    }
    sum-=100;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(data[i]+data[j]==sum)
            {
                data[i]=100;
                data[j]=100;
                sort(data,data+n);
                for(int k=0 ; k<7 ; k++)
                {
                    printf("%d\n",data[k]);
                }
                return 0;
            }
        }
    }
}
