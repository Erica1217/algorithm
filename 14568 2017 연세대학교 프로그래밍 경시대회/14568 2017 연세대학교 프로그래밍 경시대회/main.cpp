//
//  main.cpp
//  14568 2017 연세대학교 프로그래밍 경시대회
//
//  Created by 김유진 on 19/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    int dap=0;
    scanf("%d",&n);
    for(int i=2 ; i<=n-2 ; i+=2)
    {
        dap+=((n-i)/2)-1;
    }
    printf("%d",dap);
}

