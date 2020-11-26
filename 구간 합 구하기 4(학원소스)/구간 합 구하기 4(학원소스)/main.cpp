//
//  main.cpp
//  구간 합 구하기 4(학원소스)
//
//  Created by 김유진 on 2020/07/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#define MAX_N 100000
int n;
long long t[MAX_N * 2 +1];

void init()
{
    for(int i=n-1 ; i>0 ; i--)
    {
        t[i] = t[i*2] + t[i*2+1];
    }
}

long long query(int l, int r)
{
    long long ans=0;
    l+=n;
    r+=n;
    do
    {
        if(l%2==1) ans+=t[l++];
        if(r%2==1) ans+=t[--r];
        l/=2;
        r/=2;
    }while(l<r);
    return ans;
}

int main()
{
    int m;
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; ++i)
    {
        scanf("%d",&t[n+i+1]);
    }
    
    init();
    for(int i=0 ; i<m ; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        long long q=query(a,b+1);
        printf("%lld\n",q);
    }
}
