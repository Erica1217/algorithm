//
//  main.cpp
//  16922 로마 숫자 만들기
//
//  Created by 김유진 on 2020/03/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[30]={0,};
int number[5]={1,5,10,50};
int result=0;
int check[1010]={0,};
int n;

void func(int num,int sum)
{
    if(num==n)
    {
        if(check[sum]==0)
        {
            result++;
            check[sum]=1;
        }
        return;
    }
    for(int i=0 ; i<4 ; i++)
    {
        if(num==0 || data[num-1]<=i)
        {
            data[num]=i;
            func(num+1,sum+number[i]);
        }
        
    }
}

int main()
{
    scanf("%d",&n);
    func(0,0);
    printf("%d",result);
}
