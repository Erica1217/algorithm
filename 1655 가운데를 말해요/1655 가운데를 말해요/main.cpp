//
//  main.cpp
//  1655 가운데를 말해요
//
//  Created by 김유진 on 2020/06/06.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <queue>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    priority_queue<int, vector<int>> a; //내림차순
    priority_queue<int,vector<int>, greater<int>> b; // 오름차순
    int input[110000]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
        a.push(input[i]);
        if(b.size()>=1 && a.top() > b.top())
        {
            int at = a.top();
            int bt = b.top();
            a.pop();
            b.pop();
            a.push(bt);
            b.push(at);
            
        }
        while(a.size() > b.size()+1)
        {
            b.push(a.top());
            a.pop();
            
        }
        printf("%d\n",a.top());
    }
}
