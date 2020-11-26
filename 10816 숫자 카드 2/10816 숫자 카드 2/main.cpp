//
//  main.cpp
//  10816 숫자 카드 2
//
//  Created by 김유진 on 2020/03/09.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
const int NUM=10000000;

int data[20000010]={0,};
int main()
{
    int n,m;
    scanf("%d",&n);
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        data[a+NUM]++;
    }
    scanf("%d",&m);
    for(int i=0 ; i<m ;i++)
    {
        scanf("%d",&a);
        printf("%d ",data[a+NUM]);
    }
}
