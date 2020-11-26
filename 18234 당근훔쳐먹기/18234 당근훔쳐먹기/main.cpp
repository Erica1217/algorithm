//
//  main.cpp
//  18234 당근훔쳐먹기
//
//  Created by 김유진 on 06/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
long long result=0;
vector<pair<int, int> > data;

bool cmp(pair<int,int> a, pair<int ,int> b)
{
    if(a.second < b.second)
    {
        return false;
    }
    else if(a.second == b.second && a.first < b.first)
    {
        return false;
    }
    return true;
}

int main()
{
    scanf("%d %d",&N,&T);
    int a,b;
    for(int i=0 ; i<N ; i++)
    {
        scanf("%d %d",&a,&b);
        data.push_back(make_pair(a,b));
    }
    
    sort(data.begin(),data.end(),cmp);
    
    
    for(int i=0 ; i<N ; i++)
    {
        T--;
        result += (long long)(data[i].first+((long long) (data[i].second*(T))));
        if(T==0)
        {
            break;
        }
//        printf("%d %d\n",input[i].first,input[i].second);
    }
    printf("%lld",result);
    return 0;
}
