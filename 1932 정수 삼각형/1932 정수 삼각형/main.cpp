//
//  main.cpp
//  1932 정수 삼각형
//
//  Created by 김유진 on 13/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n;
    int data[600][600]={0,};
    
    scanf("%d",&n);
    for(int i= 0 ; i<n ; i++)
    {
        for(int j=0 ; j<=i ; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
                  
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0; j<=i ; j++)
        {
            int a=0;
            if(j-1 >=0 && a<data[i-1][j-1])
            {
                a = data[i-1][j-1];
            }
            
            if(j<=i && a<data[i-1][j])
            {
                a=data[i-1][j];
            }
            data[i][j]+=a;
        }
    }
    
    int max=0;
    for(int i=0 ; i<n ; i++)
    {
        if(max < data[n-1][i])
        {
            max = data[n-1][i];
        }
//        printf("%d ",data[n-1][i]);
    }
    printf("%d",max);
}
