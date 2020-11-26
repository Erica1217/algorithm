//
//  main.cpp
//  10825 국영수
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<string,int> name;
typedef pair<int,int> subject;

bool compare(pair<name,subject> a, pair<name,subject> b)
{
//    국어 점수가 감소하는 순서로
//    국어 점수가 같으면 영어 점수가 증가하는 순서로
//    국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
//    모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
    if(a.first.second == b.first.second)
    {
        if(a.second.first == b.second.first)
        {
            if(a.second.second == b.second.second)
            {
                return a.first.first<b.first.first;
            }
            return a.second.second > b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first.second > b.first.second;
}

int main()
{
    int n;
    vector<pair<name,subject>> v;
    cin>>n;
    
    string a;
    int b,c,d;
    for(int i=0 ; i<n ;i++)
    {
        cin>>a>>b>>c>>d;
        v.push_back(make_pair(name(a,b), subject(c,d)));
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(int i=0 ; i< n ;i++)
    {
        cout<<v[i].first.first<<"\n";
    }
}
