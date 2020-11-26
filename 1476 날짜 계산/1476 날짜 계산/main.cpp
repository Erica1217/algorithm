//
//  main.cpp
//  1476 날짜 계산
//
//  Created by 김유진 on 2020/08/06.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int main()
{
    int E,S,M;
    scanf("%d %d %d",&E,&S,&M);
    int e=0,s=0,m=0;
    for(int i=1 ; ; i++)
    {
        if(e+1==E && s+1==S && m+1==M)
        {
            printf("%d\n",i);
            return 0;
        }
        e++;
        s++;
        m++;
        e%=15;
        s%=28;
        m%=19;
    }
}
