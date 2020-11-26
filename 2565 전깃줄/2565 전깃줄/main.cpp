//
//  main.cpp
//  2565 전깃줄
//
//  Created by 김유진 on 2020/01/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool func(pair<int, int> a, pair<int,int> b)
{
    if(a.first < b.first)
    {
        return true;
    }
    return false;
}

using namespace std;
int main()
{
    int n;
    vector<pair<int,int>> input;
    int data[1000]={0,};
    
    scanf("%d",&n);
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&a,&b);
        input.push_back(make_pair(a,b));
    }
    sort(input.begin(), input.end(), func);
    
    for(int i=1 ; i<n ; i++)
    {
        int m=0;
        for(int j=0 ; j<i ; j++)
        {
            if(input[j].second < input[i].second && data[j]+1 > m)
                m=data[j]+1;
        }
        data[i] = m;
    }
    
    int max=0;
    for(int i=0 ; i<n ; i++)
    {
        if(max < data[i])
        {
            max = data[i];
        }
    }
    printf("%d",n-max-1);
}
