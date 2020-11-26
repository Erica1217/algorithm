//
//  main.cpp
//  10872 팩토리얼
//
//  Created by 김유진 on 2020/07/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long r=1;
    for(int i=n ; i>=1; i--)
    {
        r = r*i;
    }
    printf("%lld",r);
}
