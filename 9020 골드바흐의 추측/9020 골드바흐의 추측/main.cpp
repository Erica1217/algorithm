//
//  main.cpp
//  9020 골드바흐의 추측
//
//  Created by 김유진 on 2020/01/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    int data[10010];
    int check[10010]={0,};
    int num=0;
    int n;
    
    for(int i=2 ; i<=10000 ; i++)
    {
        bool isSosu=true;
        for(int j=2 ; j<=sqrt(i) ; j++)
        {
            if(i%j==0)
            {
                isSosu = false;
                break;
            }
        }
        if(isSosu)
        {
            data[num++] = i;
            check[i]=1;
        }
    }
    
    for(int i=0 ; i<T ; i++)
    {
        scanf("%d",&n);
        int result1=0,result2=0;
          
        for(int i=0 ; i<num && data[i]<=n/2  ; i++)
        {
            if(check[n-data[i]]==1)
            {
                result1 = data[i];
                result2 = n-data[i];
            }
        }
        printf("%d %d\n",result1, result2);
    }
}
