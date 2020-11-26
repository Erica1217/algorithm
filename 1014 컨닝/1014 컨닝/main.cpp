//
//  main.cpp
//  1014 컨닝
//
//  Created by 김유진 on 2020/04/19.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int dx[5]={-1,-1,0,0};
int dy[5]={-1,1,-1,1};

int main()
{
    int t;
    scanf("%d",&t);
    for(int a=0; a<t ;a++ )
    {
        int n,m;
        char input[20][20]={0,};
        int data[23]={0,};
        scanf("%d %d",&n,&m);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%s",input[i]);
        }
        
        for(int i=0 ; i<m ; i++)
        {
            int num=0;
            for(int j=0 ; j<n ; j++)
            {
                if(input[j][i] == '.')
                {
                    num++;
                }
            }
            data[i]=num;
            printf("%d ",data[i]);
        }
        printf("\n\n\n");
        
        int sum[30]={0,};
        sum[0]=data[0];
        sum[1]=data[1];
        int result=sum[0]>sum[1]?sum[0]:sum[1];
        for(int i=2 ; i<m ;i++)
        {
            int max=0;
            for(int j=0 ; j<i-1 ; j++)
            {
                if(max<sum[j])
                {
                    max=sum[j];
                }
            }
            sum[i] = max+data[i];
            result = result<sum[i]?sum[i]:result;
            printf("%d ",sum[i]);
        }
        printf("[%d]\n",result);
    }
}
