//
//  main.cpp
//  2110 공유기 설치
//
//  Created by 김유진 on 2020/03/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
    int n,c;
    int data[210000]={0,};
    scanf("%d %d",&n,&c);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    sort(data,data+n);
    
    int left=1;
    int right=data[n-1] - data[0];
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        int a=1;
        
        int install=0;
        for(int i=1 ; i<n ; i++)
        {
            if(data[install]+mid <= data[i])
            {
                a++;
                install = i;
            }
        }
        if(a<c)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    printf("%d",right);
}
