//
//  main.cpp
//  2042 구간 합 구하기
//
//  Created by 김유진 on 2020/07/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
long long tree[4000000]={0,};

void update(long long pos)
{
    if(pos==0)
    {
        return;
    }
    pos/=2;
    tree[pos] = tree[pos*2] + tree[pos*2+1];
    update(pos);
}

long long getSum(int left, int right, long long ret)
{
    if(left%2==1)
    {
        ret+=tree[left];
        left++;
    }
    if(right%2==0)
    {
        ret+=tree[right];
        right--;
    }
    if(left==right)
    {
        ret+=tree[left];
        return ret;
    }
    if(left<right)
    {
        return getSum(left/2, right/2, ret);
    }
    return ret;
}

int main()
{
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    long long bottom=1;
    for(bottom=1 ; bottom<n ; bottom*=2){}
    
    long long a;
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a);
        tree[bottom+i]=a;
        update(bottom+i);
    }
    
    a=0;
    long long b,c;
    for(int i=0 ; i<m+k ; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1)
        {
            tree[bottom+b-1]=c;
            update(bottom+b-1);
        }
        else if(a==2)
        {
            printf("%lld\n",getSum(bottom+b-1, bottom+c-1,0));
        }
    }
}

