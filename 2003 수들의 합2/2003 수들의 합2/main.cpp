//
//  main.cpp
//  2003 수들의 합2
//
//  Created by 김유진 on 2020/04/11.
//  Copyright © 2020 김유진. All rights reserved.
//


#include <cstdio>
#include <deque>
using namespace std;

int n,m;
int input[11000];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    deque<long long> data;
    long long sum=0;
    int result=0;
    int i=0;
    while(i<n || sum>=m)
    {
        if(sum<m)
        {
            sum+=input[i];
            data.push_back(input[i]);
            i++;
        }
//        printf("%d %lld\n",i,sum);
        if(sum>=m)
        {
            if(sum==m)
            {
                result++;
            }
            long long a = data.front();
            sum-=a;
            data.pop_front();
        }
    }
    printf("%d",result);
}
