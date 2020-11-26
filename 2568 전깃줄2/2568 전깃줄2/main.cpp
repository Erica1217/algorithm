//
//  main.cpp
//  2568 전깃줄2
//
//  Created by 김유진 on 2020/04/25.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int ,int> a, pair<int, int> b)
{
    if(a.first<b.first)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    vector<pair<int, int>> input;
    scanf("%d",&n);
    
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&a,&b);
        input.push_back(make_pair(a,b));
    }
    sort(input.begin(), input.end(), cmp);
    
    
}
