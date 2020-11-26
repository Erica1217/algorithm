//
//  main.cpp
//  2738 행렬덧셈
//
//  Created by 김유진 on 2020/04/10.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,m;
    int data[110][110];
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    
    int a;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m; j++)
        {
            scanf("%d",&a);
            data[i][j]+=a;
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
}
