//
//  main.cpp
//  1890 점프
//
//  Created by 김유진 on 10/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>

using namespace std;

int main()
{
    int n;
    int input[110][110]={0,};
    long long data[110][110]={0,};
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    
    data[0][0]=1;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            int d = input[i][j];
            if(d==0)
            {
                continue;
            }
            if(d+i<n)
            {
                data[d+i][j]+=data[i][j];
            }
            if(d+j<n)
            {
                data[i][j+d]+=data[i][j];
            }
        }
    }
    printf("%lld",data[n-1][n-1]);
}
