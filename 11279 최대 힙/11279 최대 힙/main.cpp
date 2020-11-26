//
//  main.cpp
//  11279 최대 힙
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
    
    int result=0;
    priority_queue<int, vector<int>> data;
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        if(a==0)
        {
            result = 0;
            if(data.size()!=0)
            {
                result = data.top();
                data.pop();
            }
            printf("%d\n",result);
        }
        else
        {
           data.push(a);
        }
    }
}
