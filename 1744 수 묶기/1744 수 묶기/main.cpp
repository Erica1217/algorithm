//
//  main.cpp
//  1744 수 묶기
//
//  Created by 김유진 on 30/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int data[11000]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    sort(data,data+n);
    
    long long result=0;
//    음수
    for(int i=0; i<=n-1 ; i+=2)
    {
//        홀로남은 음수거나 끝 자리 시작될 때
        if((i==n-1 && data[n-1]<0) || (data[i] <0 && data[i+1]>0))
        {
            result+=data[i];
            break;
        }
        else if(i+1!=n &&data[i] <0 && data[i+1]<=0)
        {
            result+=(data[i]*data[i+1]);
        }
        else if(data[i]>0)
        {
            break;
        }
    }
       
//    양수
    for(int i=n-1 ; i>=0 ; i-=2)
    {
        if(i-1<0)
        {
            if(data[i]>0)
            {
                result+=data[i];
            }
            break;
        }
        
        if(data[i]==1)
            result++;
        if(data[i-1]==1)
            result++;
        
        if(data[i] >1 && data[i-1]>1)
        {
            result+=(data[i]*data[i-1]);
        }
        else if(data[i]>1 && data[i-1]<1)
        {
            result+=(data[i]);
            break;
        }else if(data[i]>1 && data[i-1]==1)
        {
            result+=(data[i]);
        }
        else if(data[i]<1)
        {
            break;
        }
    }
    printf("%lld",result);
}
