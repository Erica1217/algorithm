//
//  main.cpp
//  9658 돌 게임4
//
//  Created by 김유진 on 2020/04/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n;
    int data[1010]={0,};
    int d[4]={1,3,4};
    data[1]=1; //CY
    data[2]=2; //SK
    data[3]=1;
    data[4]=2;
    scanf("%d",&n);
    for(int i=5; i<=n ; i++)
    {
        data[i]=1;
        for(int j=0 ; j<3 ; j++)
        {
            int x=i-d[j];
            if(data[x]==1)
            {
                data[i]=2;
            }
        }
    }
    printf(data[n]==2?"SK":"CY");
}
