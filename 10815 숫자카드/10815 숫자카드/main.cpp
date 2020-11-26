//
//  main.cpp
//  10815 숫자카드
//
//  Created by 김유진 on 27/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&n);
    int data[510000];
    for(int i=0 ; i<n ;i++)
    {
        scanf("%d",&data[i]);
    }
    
    sort(data,data+n);
    
    scanf("%d",&m);
    int b;
    for(int i =0 ; i<m ;i++)
    {
        scanf("%d",&b);
        int front=0;
        int end = n-1;
        int middle=(end+front)/2;
        int result=0;
        while(front<=end)
        {
            if(data[middle]==b)
            {
                result=1;
                break;
            }
            else if(data[middle]<b)
            {
                front = middle+1;
            }
            else
            {
                end = middle-1;
            }
            middle = (front+end)/2;
        }
        printf("%d ",result);
    }
}
