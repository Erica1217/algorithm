//
//  main.cpp
//  1715 카드 정렬하기
//
//  Created by 김유진 on 2020/06/06.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > q;
    scanf("%d",&n);
    int input;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input);
        q.push(input);
    }
    
    int result=0;
    int a,b;
    while(q.size()!=1)
    {
        a= q.top();
        q.pop();
        b= q.top();
        q.pop();
        q.push(a+b);
        result+=a+b;
    }
    printf("%d",result);
}
