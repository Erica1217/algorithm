//
//  main.cpp
//  1644 소수의 연속합
//
//  Created by 김유진 on 2020/04/11.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
#include <vector>
#include <math.h>
using namespace std;

int check[4100000]={0,};
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=2 ; i<=sqrt(n) ; i++)
    {
        if(check[i]==0)
        {
            for(int j=i*2 ; j<=n ; j+=i)
            {
                check[j]=1;
            }
        }
    }

    
    int i=2;
    int sum=0;
    int result=0;
    deque<int> data;
    while(i<=n || sum>=n)
    {
        if(sum<n)
        {
            data.push_back(i);
            sum+=i;
            i++;
            while(check[i]!=0 && i<=n)
            {
                i++;
            }
        }
        if(sum>=n)
        {
            if(sum==n)
            {
                result++;
            }
            sum-=data.front();
            data.pop_front();
        }
    }
    printf("%d",result);
}
