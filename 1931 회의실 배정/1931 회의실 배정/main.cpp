//
//  main.cpp
//  1931 회의실 배정
//
//  Created by 김유진 on 2020/02/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<long long,long long> a, pair<long long ,long long> b)
{
    if(a.second < b.second)
    {
        return true;
    }
    else if(a.second == b.second && a.first < b.first)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    vector<pair<long long ,long long>> data;
    scanf("%d",&n);
    
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&a, &b);
        data.push_back(make_pair(a,b));
    }
    
    sort(data.begin(), data.end(), cmp);
    
    long long start=0;
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        if(data[i].first>=start)
        {
            start= data[i].second;
            result++;
        }
    }
    printf("%d",result);
}
