//
//  main.cpp
//  17070 파이프 옮기기 2
//
//  Created by 김유진 on 2020/03/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int n;
int input[50][50]={0,};
long long data[50][50][3]={0,};


int main()
{
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    
    data[0][1][0]=1;

    for(int i=0; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(i==0 && j==1)
            {
                continue;
            }
            
            if(i-1>=0 && j-1>=0 && input[i-1][j]==0
               && input[i][j-1]==0 && input[i][j]==0)
            {
                data[i][j][2] = data[i-1][j-1][0] + data[i-1][j-1][1] + data[i-1][j-1][2];
            }
            if(i-1>=0 && input[i][j]==0)
            {
                data[i][j][1] = data[i-1][j][1]+data[i-1][j][2];
            }
            if(j-1>=0 && input[i][j]==0)
            {
                data[i][j][0] = data[i][j-1][0]+data[i][j-1][2];
            }
        }
    }

    long long result=0;
    for(int i=0 ; i<3; i++)
    {
        result+=data[n-1][n-1][i];
    }
    printf("%lld",result);
}
