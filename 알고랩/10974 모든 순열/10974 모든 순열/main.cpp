//
//  main.cpp
//  10974 모든 순열
//
//  Created by 김유진 on 2020/04/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int check[10]={0,};
int data[10]={0,};
int n;
void func(int num)
{
    if(num==n)
    {
        for(int i=0 ; i<n ; i++)
        {
            printf("%d ",data[i]);
        }
        printf("\n");
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            data[num]=i;
            func(num+1);
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    func(0);
}
