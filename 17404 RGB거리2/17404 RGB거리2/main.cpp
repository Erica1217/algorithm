//
//  main.cpp
//  17404 RGB거리2
//
//  Created by 김유진 on 2020/07/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int main()
{
    int n;
    int input[1010][30];
    int data[1010][30][30];
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            data[1][i][j] = input[1][i];
        }
    }
    
    for(int i=2 ; i<=n ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            for(int k=0 ; k<3 ; k++)
            {
                int min=2100000000;
                for(int h=0 ; h<3 ; h++)
                {
                    if(min>data[i-1][k][h] && k!=h)
                    {
                        min=data[i-1][k][h];
                    }
                }
                data[i][j][k] =  min + input[i][j];
            }
        }
    }
    
    int result=2000000000;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            printf("%d \n",data[n][i][j]);
            if(result>data[n][i][j] && i!=j)
            {
                result=data[n][i][j];
            }
        }
        
    }
    printf("%d",result);
}
