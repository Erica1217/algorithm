//
//  main.cpp
//  1107 리모컨
//
//  Created by 김유진 on 2020/02/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int N;
int n;
int data[15]={0,};
int result=100;
int result_length=0;

int abs(int a)
{
    if(a<0)
        return -1*a;
    return a;
}

void func(int length, int num)
{
    int r = result_length + abs(N-result);
    int current = length + abs(N-num);
    if(r > current && num!=0)
    {
        result = num;
        result_length = length;
    }
    
    if(num>N)
    {
        return;
    }
    
    for(int i=0 ; i<=9 ; i++)
    {
        if(!(length == 0 && i==0) && data[i]==0)
        {
            func(length+1, num*10+i);
        }
    }
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&n);
    
    int a;
    for(int i= 0 ;i< n ;i++)
    {
        scanf("%d",&a);
        data[a]=1;
    }
    
    func(0,0);
    
    int r = result_length + abs(N-result);
    if(data[0]==0 && r > N+1)
    {
        r = N+1;
    }
    
    printf("%d",r);
}
