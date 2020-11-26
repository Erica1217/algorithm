//
//  main.cpp
//  9084 동전
//
//  Created by 김유진 on 09/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    for(int a=0 ; a<T ; a++)
    {
        int n;
        scanf("%d",&n);
        
        int coin[25]={0,};
        int money;
        int data[10100]={0,};
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&coin[i]);
        }
        scanf("%d",&money);
        
        data[0]=1;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=coin[i] ; j<=money ; j++)
            {
                data[j] += data[j-coin[i]];
            }
        }
        printf("%d\n", data[money]);
        
    }
}
