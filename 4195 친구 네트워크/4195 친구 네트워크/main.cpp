//
//  main.cpp
//  4195 친구 네트워크
//
//  Created by 김유진 on 2020/04/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <map>
#include <iostream>

using namespace std;
int parent[300000]={0,};
int num[300000]={0,};
int idxN=0;
int find(int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        parent[a] = b;
        int t = num[a]+num[b];
        num[a]=t;
        num[b]=t;
    }
}

int main()
{
    cin.tie(0);
    int t;
    cin>>t;
    for(int k=0 ; k<t ; k++)
    {
        int n;
        idxN=0;
        cin>>n;
        string input1[110000];
        string input2[110000];
        map<string,int> m;
        for(int i=0 ; i<n ; i++)
        {
            cin>>input1[i]>>input2[i];
            if(m.find(input1[i]) == m.end())
            {
                m.insert(make_pair(input1[i],idxN));
                idxN++;
            }
            if(m.find(input2[i]) == m.end())
            {
                m.insert(make_pair(input2[i],idxN));
                idxN++;
            }
        }
        
        for(int i=0 ; i<n*2+1 ; i++)
        {
            parent[i]=i;
            num[i]=1;
        }
        
        for(int i=0 ; i<n ; i++)
        {
            int idx1= m.find(input1[i])->second;
            int idx2= m.find(input2[i])->second;
            merge(idx1,idx2);
            printf("%d\n",num[parent[idx1]]);
        }
    }
}
