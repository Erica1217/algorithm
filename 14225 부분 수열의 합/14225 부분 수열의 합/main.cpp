//
//  main.cpp
//  14225 부분 수열의 합
//
//  Created by 김유진 on 2020/07/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int data[25]={0,};
int check[25]={0,};
int result[21000000]={0,};
int n;

void func(int start, int sum)
{
    result[sum]=1;
    for(int i=start ; i<n ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            func(i+1,sum+data[i]);
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    func(0,0);
    for(int i=1;i<=20000010 ; i++)
    {
        if(result[i]==0)
        {
            printf("%d",i);
            return 0;
        }
    }
}
