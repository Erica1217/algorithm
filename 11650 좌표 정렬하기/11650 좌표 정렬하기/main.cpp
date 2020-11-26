//
//  main.cpp
//  11650 좌표 정렬하기
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    int n;
    vector<pair<int,int>> v;
//    cin>>n;
    scanf("%d",&n);
    
    int a,b;
    for(int i=0 ; i<n ; i++)
    {
//        cin>>a>>b;
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d %d\n",v[i].first,v[i].second);
//        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
