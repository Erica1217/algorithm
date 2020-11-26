//
//  main.cpp
//  1309 동물원
//
//  Created by 김유진 on 2020/07/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int data[110000][3][3]={0,};

int main()
{
    int n;
    
    scanf("%d",&n);
    
    
    data[1][1][0]=1;
    data[1][1][1]=1;
    data[1][2][0]=2;
    data[1][2][1]=1;
    for(int i=2; i<=n ; i++)
    {
        data[i][1][0]=(data[i-1][2][0] + data[i-1][2][1])%9901;
        data[i][1][1]=data[i-1][2][0];
        data[i][2][0]=(data[i][1][0]+data[i][1][1])%9901;
        data[i][2][1]=data[i][1][1];
    }
    long long r = data[n][2][0]+ data[n][2][1];
    printf("%lld",r%9901);
}
