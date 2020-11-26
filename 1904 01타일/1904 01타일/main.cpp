//
//  main.cpp
//  1904 01타일
//
//  Created by 김유진 on 09/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n;
    int data[1000100]={0,};
    scanf("%d",&n);
    
    data[0]=0;
    data[1]=1;
    data[2]=2;
    for(int i=3 ; i<=n ; i++)
    {
        data[i] = (data[i-1] + data[i-2])%15746;
    }
    printf("%d",data[n]%15746);
}
