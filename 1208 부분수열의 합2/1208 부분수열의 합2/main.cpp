//
//  main.cpp
//  1208 부분수열의 합2
//
//  Created by 김유진 on 2020/04/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> a;
vector<long long> b;

vector<long long> asum;
vector<long long> bsum;

void afunc(int n, int before, long long sum)
{
    asum.push_back(sum);
    for(int i=before+1 ; i<n; i++)
    {
        afunc(n, i, sum+a[i]);
    }
}
void bfunc(int n, int before ,long long sum)
{
    bsum.push_back(sum);
    for(int i=before+1 ; i<n ; i++)
    {
        bfunc(n,i,sum+b[i]);
    }
}
int main()
{
    int n,s;
    
    scanf("%d %d",&n,&s);

    int t;
    for(int i=0 ; i<n/2 ; i++)
    {
        scanf("%d",&t);
        a.push_back(t);
    }
    
    for(int i=n/2 ; i<n ; i++)
    {
        scanf("%d",&t);
        b.push_back(t);
    }

    afunc((int)a.size(), -1, 0);
    bfunc((int)b.size(),-1,0);
    sort(asum.begin(),asum.end());
    sort(bsum.begin(),bsum.end());
    
    
    int start=0, end=bsum.size()-1;
    long long result=0;
    while(start<asum.size() && end>=0)
    {
        long long sum = asum[start] + bsum[end];
        if(sum>s)
        {
            end--;
        }
        else if(sum<s)
        {
            start++;
        }
        else if(sum==s)
        {
            int an=1,bn=1;
            while(start+1<asum.size() && asum[start]==asum[start+1])
            {
                start++;
                an++;
            }
            while(end-1>=0 && bsum[end]==bsum[end-1])
            {
                end--;
                bn++;
            }
            
            start++;
            end--;
            result+= (long long)an*(long long)bn;
        }
    }
    if(s==0)
    {
        result--;
    }
    printf("%lld",result);
}
