//
//  main.cpp
//  12015 가장 긴 증가하는 수열2
//
//  Created by 김유진 on 2020/07/19.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n;
int tree[2200000]={0,};
const int MAX_N = 1000001;

void init()
{
    for(int i=MAX_N-1 ; i<MAX_N ; i++)
    {
        int l = tree[i<<1];
        int r = tree[i<<1 |1];
        tree[i] =  l<r ? r: l;
    }
}

void update(int pos, int value)
{
    tree[pos]=value;
    pos/=2;
    if(pos!=0 && value>tree[pos])
    {
        tree[pos] = value;
        update(pos,value);
    }
}

int query(int l, int r)
{
    int ret=0;
    for(l=l+MAX_N, r=r+MAX_N ; l<r ; l>>=1, r>>=1)
    {
        if(l&1)
        {
            ret = ret>tree[l]? ret:tree[l];
            l++;
        }
        if(r&1)
        {
            r--;
            ret = ret>tree[r]? ret:tree[r];
        }
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    int a;
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        
        int r=query(1,a);
        r++;
//        printf("%d %d\n",i,r);
        update(a+MAX_N,r);
    }
    printf("%d",tree[1]);
}
