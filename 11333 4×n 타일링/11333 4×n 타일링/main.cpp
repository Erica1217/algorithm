//
//  main.cpp
//  11333 4×n 타일링
//
//  Created by 김유진 on 2020/01/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

const int MAX = 10000;

const long long MOD = 1000000007;
long long cache[MAX];

void preCalc(void)
{
        cache[0] = 1;
        cache[3] = 3;
        cache[6] = 13;

        for (int i = 9; i < MAX; i += 3)
            cache[i] = (((5 * cache[i - 3]) % MOD) + MOD - ((3 * cache[i - 6]) % MOD) + cache[i - 9]) % MOD;
}

int mod(int a)
{
    return a%1000000007;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    preCalc();
    for(int a=0 ; a<n ; a++)
    {
        int t;
        int data[10100][10];
        scanf("%d",&t);
        
        data[3][0] = 3;
        data[3][1] = 0;
        for(int i=6 ; i<=t ; i+=3)
        {
            data[i][0] = mod(data[i-3][0]*data[3][0]) + mod(mod(data[i-3][1]*data[3][0])*2);
            data[i][1] = 4;
        }
        
        printf("%d %d\n",mod(data[t][1] + data[t][0]) ,cache[t]);
    }
    
}
