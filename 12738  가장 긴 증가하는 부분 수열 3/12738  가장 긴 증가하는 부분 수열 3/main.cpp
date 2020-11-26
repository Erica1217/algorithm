//
//  main.cpp
//  12738  가장 긴 증가하는 부분 수열 3
//
//  Created by 김유진 on 2020/07/19.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n;
int tree[2200000]={0,};
vector<int> input;
const int MAX_N = 1000001;

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
        input.push_back(a);
    }
    
    vector<int> v(input);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<int, int> m;
    for(int i=0; i<v.size() ; i++)
    {
        m[v[i]] = i+1;
    }
    for(int i=0 ; i<input.size() ; i++)
    {
        input[i] = m[input[i]];
    }
    
    for(int i=0 ; i<n ; i++)
    {
        int r=query(1,input[i]);
        r++;
        update(input[i]+MAX_N,r);
    }

    printf("%d",tree[1]);
}
