//
//  main.cpp
//  1181 단어 정렬
//
//  Created by 김유진 on 27/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
    if(a.size() == b.size())
    {
        return a<b;
    }
    return a.size()<b.size();
}

int main()
{
    int n;
    vector<string> v;
    cin>>n;
    
    string s;
    for(int i=0 ; i<n ; i++)
    {
        cin>>s;
        v.push_back(s);
    }
    
    sort(v.begin(),v.end(),compare);
    
    string before="";
    for(int i=0 ; i<n  ;i++)
    {
        if(before != v[i])
        {
            before = v[i];
            cout<<v[i]<<"\n";
        }
    }
}
