//
//  main.cpp
//  1495 기타리스트
//
//  Created by 김유진 on 2020/04/23.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,s,m;
    scanf("%d %d %d",&n,&s,&m);
    int input[110]={0,};
    int data[110][3]={0,};
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    data[0][0]=s;
    data[0][0]=s;
    for(int i=1 ; i<=n ; i++)
    {
        int m1 = input[i]+data[i-1][0];
        int m2 = input[i]+data[i-1][1];
        
        data[i][0]=m1>m? m2 : m2>m? m1: m1>m2? m1:m2;
        printf("%d %d\n",m1,m2);
        m1 = data[i-1][0]-input[i];
        m2 = data[i-1][1]-input[i];
        data[i][1]= m1<0? m2: m2<0? m1: m1>m2? m1:m2;
    }
    int result = data[n][0]>data[n][1]?data[n][0]:data[n][1];
    printf("%d",result);
}
