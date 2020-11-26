//
//  main.cpp
//  10819 차이를 최대로
//
//  Created by 김유진 on 2020/04/21.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
int data[10]={0,};
int check[10]={0,};
int result=-100000;

int abs(int a)
{
    return a<0?-1*a:a;
}
void func(int num, int ret, int bef)
{
    if(num==n)
    {
        if(result<ret)
        {
            result=ret;
        }
        return;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            if(num==0)
            {
                func(num+1,0,data[i]);
            }
            else
            {
                func(num+1,abs((bef-data[i]))+ret,data[i]);
            }
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
    
    func(0,0,0);
    printf("%d",result);
}
