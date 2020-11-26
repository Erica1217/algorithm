//
//  main.cpp
//  3090 차이를 최소로
//
//  Created by 김유진 on 2020/05/01.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
int input[110000]={0,};
int n,T;
using namespace std;
struct type{
    int index;
    int d;
    int number;
};
int abs(int a)
{
    return a<0?a*-1 : a;
}


struct sortf
{
    bool operator() (type a, type b)
    {
        int i=a.index;
        int x=i-1>=0? input[i]-input[i-1]:0;
        int y=i+1<n?input[i]-input[i+1]:0;
        
        int A=abs(x)<abs(y)?y:x;
        
        i=b.index;
        x=i-1>=0? input[i]-input[i-1]:0;
        y=i+1<n?input[i]-input[i+1]:0;
        int B=abs(x)<abs(y)?y:x;
        
        if(A > B)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    scanf("%d %d",&n,&T);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    priority_queue<type, vector<type>,sortf> q;
    for(int i=0 ; i<n ; i++)
    {
        type t;
        t.index = i;
        t.number = input[i];
        int x=i-1>=0? input[i]-input[i-1]:0;
        int y=i+1<n?input[i]-input[i+1]:0;
        t.d = abs(x)<abs(y)? y:x;
        q.push(t);
    }
    
//    while(q.size())
//    {
//        printf("[%d] %d %d\n",q.top().d,q.top().index,q.top().number);
//        q.pop();
//    }
    
    while(T--)
    {
        input[q.top().index]--;
        type tmp = q.top();
        
        tmp.number--;
        q.pop();
        q.push(tmp);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",input[i]);
    }
}
