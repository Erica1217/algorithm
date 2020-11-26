//
//  main.cpp
//  이상한 극장2
//
//  Created by 김유진 on 2020/04/25.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int start=0;
    for(int i=1 ; i<=n ; i*=2)
    {
        start=i;
    }
    start*=2;
    int data[150000];
    int dp[110000]={0,};
    for(int i=start ; i<start+n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    dp[start]=0;
    for(int i=start+1 ; i<start+n ; i++)
    {
        int l=start,r=i-1;
        int v=-1;
        while(l<r)
        {
            if(l%2==1)
            {
                if(data[l]<data[i] && (dp[v]<dp[l]||v==-1))
                {
                    v=l;
                }
                l--;
            }
            if(r%2==0)
            {
                if(data[r]<data[i] && (dp[v]<dp[r]||v==-1))
                {
                    v=r;
                }
                r++;
            }
            l/=2;
            r/=2;
        }
        if(l==r)
        {
            if(data[l]<data[i] && (dp[v]<dp[r]||v==-1))
            {
                v=l;
            }
        }
        dp[i]=dp[v]+1;
        printf("%d %d\n",i-start,v);
    }
    
    for(int i=start ; i<start+n ; i++)
    {
        printf("%d ",dp[i]);
    }
}
