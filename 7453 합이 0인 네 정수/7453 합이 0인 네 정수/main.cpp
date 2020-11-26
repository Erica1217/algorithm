//
//  main.cpp
//  7453 합이 0인 네 정수
//
//  Created by 김유진 on 2020/04/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ab;
vector<int> cd;
int input[4100][10]={0,};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            int sum = input[i][0]+input[j][1];
            ab.push_back(sum);
        }
    }
    
    for(int i=0 ; i< n ;i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            int sum = input[i][2]+input[j][3];
            cd.push_back(sum);
        }
    }
    
    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());
    
    int start=0,end=cd.size()-1;
    long long result=0;
    while(start<ab.size() && end>=0)
    {
        long long sum = ab[start] + cd[end];
//        printf("%lld %d %d [%d+%d]\n",sum,start, end,ab[start],cd[end]);
        if(sum==0)
        {
            int an=1, bn=1;
            while(start+1<ab.size() && ab[start]==ab[start+1])
            {
                an++;
                start++;
            }
            
            while(end-1>=0 && cd[end]==cd[end-1])
            {
                bn++;
                end--;
            }
            start++;
            end--;
            
            result+=(long long)an*(long long)bn;
        }
        else if(sum<0)
        {
            start++;
        }
        else if(sum>0)
        {
            end--;
        }
    }
    printf("%lld",result);
}
