//
//  main.cpp
//  2370 시장 선거 포스터
//
//  Created by 김유진 on 2020/05/02.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct poster{
    int num;
    int time;
    bool isLeft;
};

bool cmp(poster a, poster b)
{
    if(a.time<b.time)
    {
        return true;
    }
    else if(a.time==b.time && a.isLeft == b.isLeft)
    {
        if(a.num < b.num)
         {
             return true;
         }
         else
         {
             return false;
         }
    }
    else if(a.time==b.time && a.isLeft && !b.isLeft)
    {
        return true;
    }
    return false;
}
int main()
{
//            freopen("input.txt","r",stdin);
//        int T;
//        scanf("%d",&T);
//        while(T--)
//        {
    
    int n;
    int check[110000]={0,};
    int poped[110000]={0,};
    priority_queue<int, vector<int> > q;
    vector<poster> data;
    scanf("%d",&n);
    int a,b;
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&a,&b);
        poster p;
        p.num=i;
        p.time = a;
        p.isLeft = true;
        data.push_back(p);
        
        p.num=i;
        p.time = b;
        p.isLeft = false;
        data.push_back(p);
    }
    
    sort(data.begin(), data.end(),cmp);
    for(int i=0 ; i<n*2 ; i++)
    {
        poster t = data[i];
        if(t.isLeft)
        {
            q.push(t.num);
        }
        
        if(i+1<n*2 && t.time == data[i+1].time && t.isLeft == data[i+1].isLeft)
        {
            if(!t.isLeft)
            {
                poped[t.num]=1;
//                poped[data[i+1]]=1;
            }
            continue;
        }
        
        int top=-1;
        while(!q.empty())
        {
            if(poped[q.top()]==1)
            {
                q.pop();
            }
            else
            {
                top = q.top();
                break;
            }
        }
        
        if(top!=-1 && check[top]==0 && poped[top]==0)
        {
            check[top]=1;
            result++;
        }
        
        if(!t.isLeft)
        {
            poped[t.num]=1;
        }
    }
    printf("%d\n",result);
//        }
}
