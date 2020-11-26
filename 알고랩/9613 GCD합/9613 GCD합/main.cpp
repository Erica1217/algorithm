//
//  main.cpp
//  9613 GCD합
//
//  Created by 김유진 on 2020/04/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int data[110]={0,};
        scanf("%d ",&n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&data[i]);
        }
        long long result=0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1; j<n ; j++)
            {
                int x= data[i];
                int y= data[j];
                for(int k=x ; k>=1 ; k--)
                {
                    if(x%k==0 && y%k==0)
                    {
                        result+=k;
                        break;
                    }
                }
            }
        }
        printf("%lld\n",result);
    }
}
