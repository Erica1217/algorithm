//
//  main.cpp
//  9657 돌 게임3
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
    data[1]=1; //SK
    data[2]=2; //CY
    data[3]=1;
    data[4]=1;
    scanf("%d",&n);
    for(int i=5; i<=n ; i++)
    {
        data[i]=2;
        for(int j=0 ; j<3 ; j++)
        {
            int x=i-d[j];
            if(data[x]==2)
            {
                data[i]=1;
            }
        }
    }
    printf(data[n]==1?"SK":"CY");
}
