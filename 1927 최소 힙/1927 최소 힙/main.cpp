//
//  main.cpp
//  1927 최소 힙
//
//  Created by 김유진 on 2020/05/01.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    priority_queue<int,vector<int>,greater<int> > q;
    int a=0;
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        result=0;
        if(a==0)
        {
            if(q.size()!=0)
            {
                result = q.top();
                q.pop();
            }
            printf("%d\n",result);
        }
        else
        {
            q.push(a);
        }
    }
}
