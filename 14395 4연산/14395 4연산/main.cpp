//
//  main.cpp
//  14395 4연산
//
//  Created by 김유진 on 2020/10/07.
//  Copyright © 2020 김유진. All rights reserved.
//
#include <queue>
#include <string>
#include <iostream>
#include <set>
using namespace std;
struct type{
    int num;
    long long s;
    string str;
};

int main()
{
    int s,t;
    cin>>s>>t;
    
    if(s==t)
    {
        cout<<"0";
        return 0;
    }
    
    queue<type> q;
    type tmp;
    tmp.num=0;
    tmp.s = s;
    tmp.str="";
    q.push(tmp);
    
    set<long long> check;
    check.insert(s);
    
    while(!q.empty())
    {
        type a=q.front();
        q.pop();
        long long ss = a.s;
         
        if(ss==t)
        {
            cout<<a.str<<endl;
            return 0;
        }
        
        auto iter = check.find(ss*ss);
        if(ss*ss>=0 && ss*ss<=1000000000 && iter == check.end())
        {
            check.insert(ss*ss);
            type tmp;
            tmp.num = a.num+1;
            tmp.s = ss*ss;
            tmp.str = a.str+"*";
            q.push(tmp);
            
        }
        iter = check.find(ss+ss);
        if(ss+ss>=0 && ss+ss<=1000000000 && iter == check.end())
        {
            check.insert(ss+ss);
            type tmp;
            tmp.num = a.num+1;
            tmp.s = ss+ss;
            tmp.str = a.str+"+";
            q.push(tmp);
        }
        iter = check.find(ss-ss);
        if(iter == check.end())
        {
            check.insert(ss-ss);
            type tmp;
            tmp.num = a.num+1;
            tmp.s = ss-ss;
            tmp.str = a.str+"-";
            q.push(tmp);
            
        }
        iter = check.find(ss/ss);
        if(ss!=0 && iter == check.end())
        {
            check.insert(ss/ss);
            type tmp;
            tmp.num = a.num+1;
            tmp.s = ss/ss;
            tmp.str = a.str+"/";
            q.push(tmp);
        }
    }
    cout<<"-1";
}
