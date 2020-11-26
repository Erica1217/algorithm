//
//  main.cpp
//  1149 RGB거리
//
//  Created by 김유진 on 13/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n;
    int data[1010][1010];
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    
    for(int i=1 ; i<n ;i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            int a=99999999;
            for(int k=0 ; k<3 ; k++)
            {
                if(k!=j && a > data[i-1][k])
                    a = data[i-1][k];
            }
            data[i][j] +=a;
        }
    }
    
    int min=data[n-1][0];
    
    for(int i=0 ; i<3; i++)
    {
        if(min > data[n-1][i])
            min = data[n-1][i];
    }
    printf("%d",min);
}
