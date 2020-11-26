//
//  main.cpp
//  2613 숫자구슬
//
//  Created by 김유진 on 2020/09/25.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int main()
{
    int n,m;
    int input[330]={0,};
    int data[330][330]={0,};
    int result[330][330]={0,};
    int result2[330][330];
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        data[i][i]=input[i];
        for(int j=i+1 ; j<n ; j++)
        {
            data[i][j]= data[i][j-1]+input[j];
        }
    }
    
    for(int i=0 ; i<n; i++)
    {
        result[0][i] = data[0][i];
    }
    for(int i=1 ; i<n ; i++)
    {
        result[1][i] = data[0][i];
        for(int j=0 ; j<i ; j++)
        {
            int t = max(data[0][j] , data[j+1][i]);
            if(t < result[1][i])
            {
                result[1][i] = t;
                result2[1][i] = j;
            }
        }
    }
    
    for(int i=2; i<m ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            result[i][j] = data[0][j];
            result2[i][j]= j;
            for(int k=i-1; k<j ; k++)
            {
                int t = max(result[i-1][k], data[k+1][j]);
                if(t<result[i][j])
                {
                    result[i][j]=t;
                    result2[i][j]=k;
                }
            }
        }
    }
    printf("%d\n",result[m-1][n-1]);
    
    int idx=result2[m-1][n-1];
    int stack[500]={0,};

    for(int i=m-1 ; i>=1 ; i--)
    {
        stack[i]=idx;
        idx = result2[i-1][idx];
    }
    stack[0]=-1;
    stack[m]=n-1;
    for(int i=0 ; i<m ; i++)
    {
//        printf("%d ",stack[i]);
        int a = stack[i+1]-stack[i];
        if(a!=0)
            printf("%d ",a);
    }
}

