//
//  main.cpp
//  2143 두 배열의 합
//
//  Created by 김유진 on 2020/04/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    int n,m;
    int inputA[1010]={0,};
    int inputB[1010]={0,};
    vector<long long> a;
    vector<long long> b;
    scanf("%d",&t);
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&inputA[i]);
    }
    scanf("%d",&m);
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d",&inputB[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        int sum=0;
        for(int j=i ; j<n ; j++)
        {
            sum+=inputA[j];
            a.push_back(sum);
        }
    }
    
    for(int i=0 ; i<m ; i++)
    {
        int sum=0;
        for(int j=i ; j<m ; j++)
        {
            sum+=inputB[j];
            b.push_back(sum);
        }
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int start=0;
    int end=b.size()-1;
    
    long long result=0;
    long long sum=0;
    while(start<a.size() && end>=0)
    {
        sum = a[start]+b[end];
        if(sum==t)
        {
            int an=1,bn=1;
            while(start+1<a.size() && a[start] == a[start+1])
            {
                start++;
                an++;
            }
            
            while(end-1>=0 && b[end] == b[end-1])
            {
                bn++;
                end--;
            }
            result+=(long long)an*(long long)bn;
            start++;
            end--;
        }
        else if(sum<t)
        {
            start++;
        }
        else if(sum>t)
        {
            end--;
        }
    }
    printf("%lld",result);
}
