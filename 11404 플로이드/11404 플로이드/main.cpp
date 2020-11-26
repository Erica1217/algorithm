//
//  main.cpp
//  11404 플로이드
//
//  Created by 김유진 on 2020/08/07.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int data[110][110]={0,};
    int a,b,c;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(data[a][b]==0 || data[a][b] >c)
            data[a][b]=c;
    }
    
    for(int k=1; k<=n ; k++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=n ; j++)
            {
                if((data[i][j]==0 || data[i][j] > data[i][k]+data[k][j])&&
                   (data[i][k]!=0 && data[k][j]!=0) && i!=j)
                {
                    data[i][j]= data[i][k]+data[k][j];
                }
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
}
