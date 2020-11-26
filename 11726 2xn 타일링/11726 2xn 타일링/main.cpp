//
//  main.cpp
//  11726 2xn 타일링
//
//  Created by 김유진 on 12/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    int data[1010]={0,};
    scanf("%d",&n);
    data[1]=1;
    data[2]=2;
    for(int i=3; i<=n ; i++)
    {
        data[i] = (data[i-1] + data[i-2])%10007;
    }
    printf("%d",data[n]);
}
