//
//  main.cpp
//  12865 평범한 배낭
//
//  Created by 김유진 on 2020/01/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[110][100100]={0,};
int input[110][2];

int max(int a, int b)
{
    return a>b? a:b;
}

int main()
{
    int n,k;

    scanf("%d %d",&n,&k);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d %d",&input[i][0], &input[i][1]);
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=0 ; j<input[i][0] ; j++)
        {
            data[i][j] = data[i-1][j];
        }
        
        for(int j=input[i][0] ; j<=k ; j++)
        {
            data[i][j] = max(data[i-1][j], input[i][1] + data[i-1][j-input[i][0]]);
        }
    }
//    for(int i=0 ; i<=k ; i++)
//    {
//        printf("%d ",data[n][i]);
//    }
    printf("%d",data[n][k]);
}
