//
//  main.cpp
//  9662 돌 게임 8
//
//  Created by 김유진 on 2020/04/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int m,k;
    int input[30]={0,};
    int data[600]={0,};
    scanf("%d %d",&m,&k);
    for(int i=0; i<k ; i++)
    {
        scanf("%d",&input[i]);
        data[input[i]]=1;
    }
    
    int max=0;
    int num=0;
    for(int i=1 ; i<=input[k-1]*2 ; i++)
    {
        if(data[i]==0)
        {
            for(int j=0 ; j<k ; j++)
            {
                int x=input[j]+i;
                data[x]=1;
            }
            max=i;
            num++;
        }
        
    }
    
    int result=0;
    printf("%d %d [%d]\n",num,m/max,max);
    result+=(num*(m/max));
    for(int i=1 ; i<=m%max ; i++)
    {
        if(data[i%max]==0)
        {
            result++;
        }
    }
    printf("%d",result);
}
