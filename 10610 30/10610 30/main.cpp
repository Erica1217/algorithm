//
//  main.cpp
//  10610 30
//
//  Created by 김유진 on 2020/04/21.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
char data[110000]={0,};
int main()
{
    scanf("%s",data);
    int n=strlen(data);
    int sum=0;
    bool hasZero=false;
    for(int i=0 ; i<n ; i++)
    {
        sum+=(data[i]-'0');
        if(data[i]=='0')
        {
            hasZero=true;
        }
    }
    if(sum%3==0 && hasZero)
    {
        sort(data,data+n);
        for(int i=n-1 ; i>=0 ; i--)
        {
            printf("%c",data[i]);
        }
    }
    else
    {
        printf("-1");
    }
}
