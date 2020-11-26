//
//  main.cpp
//  1806 부분합
//
//  Created by 김유진 on 2020/04/11.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>

using namespace std;
int main()
{
    int n,s;
    int input[110000]={0,};
    scanf("%d %d",&n,&s);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    long long sum=0;
    deque<int> data;
    int i=0;
    int result=0;
    while(i<n || sum>=s)
    {
        if(sum<s)
        {
            sum+=input[i];
            data.push_back(input[i]);
            i++;
        }
        if(sum>=s)
        {
            if(result>data.size() || result==0)
            {
                result=data.size();
            }
            sum-=data.front();
            data.pop_front();
        }
    }
    printf("%d",result);
}
