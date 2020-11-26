//
//  main.cpp
//  18436 수열과 쿼리 37
//
//  Created by 김유진 on 2020/07/19.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n,m;
int t[220000]={0,};

void init()
{
    for(int i=n-1 ;i>=1 ; i--)
    {
        t[i] = t[i<<1] + t[i<<1 | 1];
    }
}

void update(int pos)
{
    if(pos==0)
    {
        return;
    }
    pos/=2;
    t[pos] = t[pos<<1] + t[pos<<1 | 1];
    update(pos);
}

int query(int l, int r)
{
    int ret=0;
    for(l=l+n, r=r+n ; l<r ; l>>=1, r>>=1)
    {
        if(l&1) ret+=t[l++];
        if(r&1) ret+=t[--r];
    }
    return ret;
}

int main()
{
    int input[110000]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
        if(input[i]&1)
        {
            t[n+i+1]=1;
        }
    }
    init();
    scanf("%d",&m);
    int a,b,c;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        
        switch (a) {
            case 1:
                t[n+b] = c&1? 1:0;
                update(n+b);
                break;
            case 2:
                printf("%d\n",(c-b+1)-query(b,c+1));
                break;
            case 3:
                printf("%d\n",query(b,c+1));
                break;
        }
    }
}
