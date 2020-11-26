//
//  main.cpp
//  1080 행렬
//
//  Created by 김유진 on 2020/02/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,m;
    char a[55][55];
    char b[55][55];
    scanf("%d %d",&n,&m);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",a[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s", b[i]);
    }
    
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(a[i][j] != b[i][j])
            {
                if(i<n-2 && j<m-2)
                {
                    for(int k=0 ; k<3 ; k++)
                    {
                        for(int l=0 ; l<3 ; l++)
                        {
                            a[i+k][j+l] = (a[i+k][j+l]=='0') ? '1' : '0';
                        }
                    }
                    result++;
                    
//                    printf("%d %d\n",i, j);
//                    for(int q=0 ; q<n ; q++)
//                    {
//                        for(int w=0 ; w<m ; w++)
//                        {
//                            printf("%c",a[q][w]);
//                        }
//                        printf("\n");
//                    }
                }
            }
        }
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(a[i][j] != b[i][j])
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d",result);
}
