//
//  main.cpp
//  2357 최댓값과 최솟값
//
//  Created by 김유진 on 2020/07/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int minTree[400000]={0,};
int maxTree[400000]={0,};
int bottom=1;

void minUpdate(int pos, int data)
{
    minTree[pos]=data;
    if(pos/2!=0 && (minTree[pos/2]>data|| minTree[pos/2]==0))
    {
        minUpdate(pos/2, data);
    }
    return;
}

void maxUpdate(int pos, int data)
{
    maxTree[pos]=data;
    if(pos/2!=0 && maxTree[pos/2]<data)
    {
        maxUpdate(pos/2, data);
    }
    return;
}

int getMin(int left, int right, int ret)
{
    if(left%2==1)
    {
        ret = ret<minTree[left] ? ret:minTree[left];
        left++;
    }
    if(right%2==0)
    {
        ret = ret<minTree[right] ? ret:minTree[right];
        right--;
    }
    if(left<right)
    {
        return getMin(left/2, right/2, ret);
    }
    if(left==right)
    {
        ret = ret<minTree[right] ? ret:minTree[right];
    }
    return ret;
}

int getMax(int left, int right, int ret)
{
    if(left%2==1)
    {
        ret = ret>maxTree[left] ? ret:maxTree[left];
        left++;
    }
    if(right%2==0)
    {
        ret = ret>maxTree[right] ? ret:maxTree[right];
        right--;
    }
    if(left<right)
    {
        return getMax(left/2, right/2, ret);
    }
    if(left==right)
    {
        ret = ret>maxTree[right] ? ret:maxTree[right];
    }
    return ret;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(bottom=1 ; bottom<n ; bottom*=2){}
    
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        minUpdate(bottom+i,a);
        maxUpdate(bottom+i,a);
    }
    
    int left, right;
    
    for(int i=0 ; i<m ;i++)
    {
        scanf("%d %d",&left, &right);
        printf("%d ",getMin(bottom+left-1,bottom+right-1,1000000001));
        printf("%d\n",getMax(bottom+left-1,bottom+right-1,0));
    }
}
