//
//  main.cpp
//  1094 막대기
//
//  Created by 김유진 on 26/07/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    int dap=0;
    scanf("%d",&n);
    
    while(n!=0){
        dap += (n%2);
        n/=2;
    }
    printf("%d",dap);
}
