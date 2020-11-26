//
//  main.cpp
//  10814 나이순 정렬
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<int,pair<int,string>> a, pair<int,pair<int,string>> b)
{
    if(a.second.first==b.second.first)
        return a.first<b.first;
    return a.second.first<b.second.first;
}

int main()
{
    int n;
    vector<pair<int,pair<int,string>>> v;
    scanf("%d",&n);
    
    int a;
    string b;
    for(int i=0 ; i<n ; i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(i, make_pair(a, b)));
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(int i=0 ; i<n ; i++)
    {
        pair<int,string> p=v[i].second;
        cout<<p.first<<" "<<p.second<<"\n";
    }
}
