//
//  main.cpp
//  2749 피보나치수 3
//
//  Created by 김유진 on 2020/04/10.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

int data[2000000]={0,};
int check[2000000]={0,};
int main()
{
    long long n;
    scanf("%lld",&n);
    data[0]=0;
    data[1]=1;
    int start=0, end=0;
    for(int i=2 ; i<2000000 ; i++)
    {
        int a = (data[i-1]+data[i-2])%1000000;
        data[i] = a;
        if(check[a]!=0 && data[check[a]-1]==data[i-1])
        {
            end=i;
            start = check[a]-1;
            break;
        }
        check[a]=i;
        data[i] = a;
    }
    
    end-=2;
    if(n<end)
    {
        printf("%d",data[n]);
    }
    else{
        int r=end-start+1;
        int idx = ((n-start)%r)+start;
        printf("%d",data[idx]);
    }
}
