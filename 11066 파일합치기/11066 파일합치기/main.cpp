//
//  main.cpp
//  11066 파일합치기
//
//  Created by 김유진 on 2020/03/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int T;
    scanf("%d",&T);
    int n;
    int input[600]={0,};
    int data[600][600]={0,};
    for(int a=0 ; a<T ; a++)
    {
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&input[i]);
        }
        
        for(int i=1 ; i<n ; i++)
        {
            data[i-1][i] = input[i]+input[i-1];
        }
        
        for(int i=2 ; i<n ; i++)
        {
            for(int j=i; j<n ; j++)
            {
                int left = data[j-i][j-1]*2 + input[i];
                int bottom = data[j-i+1][j]*2 + input[j-i];
                data[j-i][j] = left<bottom ?left:bottom;
                printf("%d %d\n",left,bottom);
            }
            printf("\n");
        }
        printf("\n\n");
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                printf("%d ",data[i][j]);
            }
            printf("\n");
        }
    }
}
