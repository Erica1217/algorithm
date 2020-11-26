//
//  main.cpp
//  10999 구간 합 구하기2
//
//  Created by 김유진 on 2020/07/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <map>
long long t[2100000]={0,};
int n,m, k;
long long add[2100000]={0,};


void init()
{
    for(int i=n ; i>=1 ; i--)
    {
        t[i] = t[i<<1] + t[i<<1 | 1];
    }
}

long long query(long long l, long long r)
{
    int ret=0;
    for(l=n+l, r=n+r ; l<r ; l>>=1, r>>=1)
    {
        if(l&1) ret+=t[l++];
        if(r&1) ret+=t[--r];
    }
    return ret;
}

void update(long long pos, long long val)
{
    do{
        t[pos]+=val;
        pos>>=1;
    }while(!pos);
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%lld",&t[n+i+1]);
    }
    init();
    
    long long a,b,c,d;
    for(int i=0 ; i<m+k ; i++)
    {
        scanf("%lld",&a);
        if(a==1)
        {
            scanf("%lld %lld %lld",&b,&c,&d);
            for(long long j=b ; j<=c ; j++)
            {
                update(j+n,d);
            }
        }
        else
        {
            scanf("%lld %lld",&b,&c);
            printf("%lld\n",query(b,c+1));
        }
    }
}
