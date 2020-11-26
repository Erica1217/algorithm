//
//  main.cpp
//  1003 피보나치 함수
//
//  Created by 김유진 on 13/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int data[50][2]={0,};
    int T;
    scanf("%d",&T);
    
    int n;
    for(int a=0 ; a<T ;a++)
    {
        scanf("%d",&n);
        
        data[0][0]=1;
        data[0][1]=0;
        
        data[1][0]=0;
        data[1][1]=1;
        for(int i=2 ; i<=n ; i++)
        {
            data[i][0] = data[i-2][0] + data[i-1][0];
            data[i][1] = data[i-2][1] + data[i-1][1];
        }
        
        printf("%d %d\n",data[n][0], data[n][1]);
    }
}
