//
//  main.cpp
//  4811 알약
//
//  Created by 김유진 on 2020/05/10.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
unsigned long long result=0;
void func(int num,unsigned long long w, unsigned long long h)
{
    if(num==n*2)
    {
        result++;
    }
    if(w<n)
    {
        func(num+1,w+1,h);
    }
    if(h<w){
        func(num+1,w,h+1);
    }
}

using namespace std;
int main()
{
    scanf("%d",&n);
    while(n)
    {
        result=0;
        func(0,0,0);
        printf("%lld\n",result);
        scanf("%d",&n);
    }
}
