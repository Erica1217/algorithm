//
//  main.cpp
//  15989 1, 2, 3 더하기 4
//
//  Created by 김유진 on 2020/03/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int T;
    int data[11000][4]={0,};
    
    data[1][1]=1;
    data[2][1]=1;
    data[2][2]=1;
    data[3][1]=2;
    data[3][3]=1;
    scanf("%d",&T);
    for(int a=0 ; a<T ; a++)
    {
        int n;
        scanf("%d",&n);
        
        for(int i=4 ; i<=n ; i++)
        {
            data[i][1] = data[i-1][1]+data[i-1][2]+data[i-1][3];
            data[i][2] = data[i-2][2] + data[i-2][3];
            data[i][3] = data[i-3][3];
        }
        int sum = data[n][1]+data[n][2]+data[n][3];
        printf("%d\n",sum);
    }
}
