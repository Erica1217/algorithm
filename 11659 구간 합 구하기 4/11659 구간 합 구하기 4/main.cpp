//
//  main.cpp
//  11659 구간 합 구하기 4
//
//  Created by 김유진 on 2020/07/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int tree[400000]={0,};

void update(int pos)
{
    pos/=2;
    if(pos!=0)
    {
        tree[pos] = tree[pos*2] + tree[pos*2+1];
        update(pos);
    }
    return;
    
}

int getSum(int left, int right, int ret)
{
    if(left==right)
    {
        ret+=tree[left];
        return ret;
    }
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
    if(left<right)
    {
        return getSum(left/2, right/2, ret);
    }
    return ret;
    
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    int bottom=1;
    for(bottom=1 ; bottom<n ; bottom*=2){}
    
    int a;
    for(int i=0; i< n ;i++)
    {
        scanf("%d",&a);
        tree[bottom+i]=a;
        update(bottom+i);
    }
    int l,r;
    for(int i=0 ; i<m ;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n", getSum(bottom+l-1,bottom+r-1,0));
    }
}

