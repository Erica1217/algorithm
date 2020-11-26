//
//  main.cpp
//  2745 진법 변환
//
//  Created by 김유진 on 2020/07/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    char data[110000]={0,};
    int b;
    scanf("%s",data);
    scanf("%d",&b);
    
    int n= strlen(data);
    long long result=0;
    long long a=1;
    for(int i=n-1 ; i>=0 ; i--)
    {
        int r=0;
        if('A'<=data[i] && data[i]<='Z')
        {
            r=data[i]-'A'+10;
        }
        else{
            r=data[i]-'0';
        }
        
        result+= a*r;
        a*=b;
    }
    printf("%lld",result);
}
