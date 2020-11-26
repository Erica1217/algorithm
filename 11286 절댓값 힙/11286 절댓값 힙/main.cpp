//
//  main.cpp
//  11286 절댓값 힙
//
//  Created by 김유진 on 2020/06/06.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;
int abs(int x)
{
    return x<0 ? x*-1 : x;
}

struct sortf{
    bool operator()(int a, int b) {
        if(abs(a) < abs(b))
        {
            return 0;
        }
        else if(abs(a) == abs(b) && a<b)
        {
            return 0;
        }
        return 1;
    }
};

int main()
{
    int n;
    priority_queue<int, vector<int>, sortf> q;
    scanf("%d",&n);
    int a;
    for(int i=0; i<n ; i++)
    {
        scanf("%d",&a);
        if(a==0)
        {
            if(q.size()==0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",q.top());
                q.pop();
            }
        }
        else
        {
            q.push(a);
        }
    }
}
