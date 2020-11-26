//
//  main.cpp
//  2565 전깃줄(2)
//
//  Created by 김유진 on 2020/04/25.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    vector<pair<int,int>> data;
    scanf("%d",&n);
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&a,&b);
        data.push_back(make_pair(a,b));
    }
    
    int dp[110]={0,};
    sort(data.begin(),data.end(),cmp);
    for(int i=0 ; i<n ; i++)
    {
        int max=0;
        for(int j=0 ; j<i ; j++)
        {
            if(dp[j]>max && data[j].second < data[i].second)
            {
                max=dp[j];
            }
        }
        dp[i]=max+1;
    }
    
    int max=0;
    for(int i=0 ; i<n ; i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
        }
    }
    printf("%d",n-max);
}
