//
//  main.cpp
//  1300 k번째 수
//
//  Created by 김유진 on 2020/10/07.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    
    int l=1,r=k;
    int m = (l+r)/2;
    //내 앞에 k-1개의 작은 수가 있다 == k번째
//    k--;
    bool isExist=false;
    while(l<r)
    {
        m=(l+r)/2;
        long long sum=0;
        for(int i=1 ; i<=min(m,n) ; i++)
        {
            sum+= min(m/i,n);
            if(m%i==0 && i<=n && m/i<=n)
            {
                isExist=true;
            }
            if(sum>k)
            {
                break;
            }
        }
        

        if(sum<k)
        {
            l=m+1;
        }
        else if(sum>k)
        {
            r=m;
        }
        else if(sum==k)
        {
            cout<<m;
            return 0;
        }
    }
    cout<<l<<endl;
}
