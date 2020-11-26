//
//  main.cpp
//  15991 1, 2, 3 더하기 6
//
//  Created by 김유진 on 2020/08/31.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int data[11000000]={0,};
int result[11000000]={0,};
int main()
{
    int T;
    scanf("%d",&T);
    data[1]= 1;
    data[2] = 2;
    data[3] = 4;
    for(int i=4 ; i<=100000 ; i++)
    {
        data[i] = ((data[i-1]+data[i-2])%1000000009+data[i-3])%1000000009;
    }
    result[1] = 1;
    result[2] = 2;
    result[3] = 2;
    result[4] = 3;
    for(int i=5 ; i<=100000 ; i++)
    {
        if(i%2)
        {
            result[i] = (data[(i-1)>>1]+data[(i-3)>>1])%1000000009;
        }
        else
        {
            result[i] = (data[i>>1]+data[(i-2)>>1])%1000000009;
        }
    }
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",result[n]);
    }
}
