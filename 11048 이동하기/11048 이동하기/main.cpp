//
//  main.cpp
//  11048 이동하기
//
//  Created by 김유진 on 2020/02/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n,m ;
int data[1010][1010]={0,};
int result[1010][1010]={0,};
int dx[4]={1,0,1};
int dy[4]={0,1,1};

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    
    result[0][0] = data[0][0];
    for(int i=1 ; i<m ; i++)
    {
        result[0][i] = result[0][i-1] + data[0][i];
    }
    
    for(int i=1 ; i<n ;i++)
    {
        for(int j=0 ; j<m ;j++)
        {
            if(j==0)
            {
                result[i][j] = result[i-1][j] + data[i][j];
            }
            else
            {
                int m= max(max(result[i-1][j],result[i-1][j-1]),result[i][j-1]);
                result[i][j] = m + data[i][j];
            }
        }
    }
    
//    for(int i=0 ; i<n ; i++)
//    {
//        for(int j=0 ; j<m ; j++)
//        {
//            printf("%d ",result[i][j]);
//        }
//        printf("\n");
//    }
    printf("%d",result[n-1][m-1]);
}
