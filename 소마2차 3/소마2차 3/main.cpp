//
//  main.cpp
//  소마2차 3
//
//  Created by 김유진 on 2020/04/26.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct type{
    int i;
    int s;
    int e;
};

bool cmp(type a, type b)
{
    if(a.s<b.s)
    {
        return true;
    }
    return false;
}

bool cmp2(type a, type b)
{
    if(a.i<b.i)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<type> input;
    int data[400000]={0,};
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&a,&b);
        type t;
        t.s = a;
        t.e= b;
        t.i = i;
        input.push_back(t);
    }
    sort(input.begin() , input.end(), cmp);

    
//    sort(input.begin(), input.end(), cmp2);
    int start=1;
    for(int i=1 ; i<=n ; i*=2)
    {
        start=i;
    }
    start*=2;
    for(int i=start ; i<start+n ; i++)
    {
        data[i] = input[i-start].e;
        int idx=i/2;
        while(idx!=0 && (data[idx]==0 || data[idx]>data[i]))
        {
            data[idx]=data[i];
            idx/=2;
        }
    }
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d %d %d\n",input[i].i,input[i].s, input[i].e);
    }
} 
