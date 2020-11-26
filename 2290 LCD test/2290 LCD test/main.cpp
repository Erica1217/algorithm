//
//  main.cpp
//  2290 LCD test
//
//  Created by 김유진 on 2020/04/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
int main()
{
    int verti[10][10]={0,};
    int hori[10][10]={0,};
    int v[5][10]={
        {4,1,2,3,7},
        {2,5,6},
        {6,1,3,4,5,7,9},
        {1,2}
    };
    int h[5][10]={
        {2,1,4},
        {3,1,7,0},
        {3,1,4,7}
    };
    
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=1 ; j<=v[i][0] ; j++)
        {
            verti[i][v[i][j]]=1;
        }
    }
    
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=1 ; j<=h[i][0] ; j++)
        {
            hori[i][h[i][j]]=1;
        }
    }
    int s;
    char n[20];
    scanf("%d %s",&s,n);
    int num = strlen(n);
    for(int i=0 ; i<5 ; i++)
    {
        if(i%2==0)
        {
            for(int j=0 ; j<num ; j++)
            {
                printf(" ");
                int a=n[j]-'0';
                char c=hori[i/2][a]==0?'-':' ';
                for(int k=0 ; k<s ; k++)
                {
                    printf("%c",c);
                }
                printf("  ");
            }
            printf("\n");
        }
        else
        {
            for(int k=0 ; k<s ; k++)
            {
                for(int j=0 ; j<num ; j++)
                {
                    int a=n[j]-'0';
                    char c1=verti[i-1][a]==0?'|':' ';
                    char c2=verti[i][a]==0?'|':' ';
                    printf("%c",c1);
                    for(int q=0 ; q<s ; q++)
                    {
                        printf(" ");
                    }
                    printf("%c ",c2);
                }
                printf("\n");
            }
        }
        
    }
}
