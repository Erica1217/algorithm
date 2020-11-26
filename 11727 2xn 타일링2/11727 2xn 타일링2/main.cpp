//
//  main.cpp
//  11727 2xn 타일링2
//
//  Created by 김유진 on 12/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int data[1010]={0,};
    data[1]=1;
    data[2]=3;
    
    for(int i=3 ; i<=n ; i++)
    {
        data[i]=(data[i-1]+(data[i-2]*2))%10007;
    }
    printf("%d",data[n]);
}
