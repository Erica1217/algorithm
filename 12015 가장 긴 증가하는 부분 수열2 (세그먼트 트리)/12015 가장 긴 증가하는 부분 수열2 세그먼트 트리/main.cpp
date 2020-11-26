//
//  main.cpp
//  12015 가장 긴 증가하는 부분 수열2 (세그먼트 트리)
//
//  Created by 김유진 on 2020/07/19.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n;
int tree[2200000]={0,};

void update(int pos)
{
    if(pos==0)
        return;
    tree[pos]++;
    pos/=2;
    update(pos);
}

int query(int l, int r, int ret)
{
    printf("%d %d\n",l,r);
    if(l&1)
    {
        ret+=tree[l];
        l++;
    }
    if(!(r&1))
    {
        ret+=tree[r];
        r--;
    }
    if(l<r)
    {
        return query(l/2,r/2,ret);
    }
    return ret+tree[l];
}

int main()
{
    scanf("%d",&n);
    int a;
    int start=1;
    
    for(start=1 ; start<n ; start*=2)
    {
        printf("%d\n",start);
    }
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        update(a+start);
        int r=query(start,a+start-1,0);
        if(r>result)
            result=r;
    }
    printf("%d",result);
}
