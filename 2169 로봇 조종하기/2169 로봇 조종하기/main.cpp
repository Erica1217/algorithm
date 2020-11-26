//
//  main.cpp
//  2169 로봇 조종하기
//
//  Created by 김유진 on 2020/01/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

const int LEFT = 0;
const int RIGHT = 1;
const int BOTTOM = 2;
const int MIN = -2100000000;

int input[1010][1010]={0,};
int data[1010][1010][3]={0,};

int max(int a,int b)
{
    return a<b?b:a;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    
    data[0][0][LEFT] = input[0][0];
    data[0][0][RIGHT] = input[0][0];
    data[0][0][BOTTOM] = input[0][0];
    
    for(int i=1 ; i<m ; i++)
    {
        data[0][i][LEFT] = data[0][i-1][LEFT] + input[0][i];
        data[0][i][RIGHT] = MIN;
        data[0][i][BOTTOM] = MIN;
    }
    
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            data[i][j][BOTTOM] = max(max(data[i-1][j][RIGHT], data[i-1][j][BOTTOM]), data[i-1][j][LEFT]) + input[i][j];
            data[i][j][LEFT] = MIN;
            data[i][j][RIGHT] = MIN;
        }
        
        for(int j=0 ; j<m ; j++)
        {
            if(j-1>=0)
            {
                data[i][j][LEFT] = max(data[i][j-1][LEFT], data[i][j-1][BOTTOM]) + input[i][j];
            }
            
            if(m-j<m && i!=n-1)
            {
                data[i][m-j-1][RIGHT] = max(data[i][m-j][RIGHT], data[i][m-j][BOTTOM]) + input[i][m-j-1];
            }
        }
    }
    
    int result = max(data[n-1][m-1][LEFT], data[n-1][m-1][RIGHT]);
    result = max(result, data[n-1][m-1][BOTTOM]);
    printf("%d",result);
}
