//
//  main.cpp
//  2616 소형기관차
//
//  Created by 김유진 on 2020/02/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[50010][5]={0,};
int guest[50010]={0,};
int n,m;

int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&guest[i]);
    }
    scanf("%d",&m);
    
    int sum=0;
    for(int i=0 ; i<m ; i++)
    {
        sum+=guest[i];
    }
    
    int num=0;
    data[num++][0] = sum;
    for(int i=m ; i<n ; i++)
    {
        sum-=guest[i-m];
        sum+=guest[i];
        data[num++][0] = sum;
    }
    
    int max1 = data[0][0];
    int max2 = 0;
    
    data[0][1] = 0;
    data[1][1] = 0;
    for(int i=2 ; i<num ; i++)
    {
        if(max1 < data[i-m][0])
        {
            max1 = data[i-m][0];
        }
        if(max2 < data[i-m][1])
        {
            max2 = data[i-m][1];
        }
        data[i][1] = max1 + data[i][0];
        data[i][2] = max2 + data[i][0];
        
        if(data[i][1] < data[i-1][1])
        {
            data[i][1] = data[i-1][1];
        }
        if(data[i][2] < data[i-1][2])
        {
            data[i][2] = data[i-1][2];
        }
    }

    int result=0;
    for(int i=0 ; i<3 ; i++)
    {
        if(result<data[num-1][i])
            result = data[num-1][i];
    }
    printf("%d",result);
}
