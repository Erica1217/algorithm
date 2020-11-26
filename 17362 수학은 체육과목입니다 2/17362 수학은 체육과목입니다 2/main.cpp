//
//  main.cpp
//  17362 수학은 체육과목입니다 2
//
//  Created by 김유진 on 02/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int data[10]={2,1,2,3,4,5,4,3,2};
    printf("%d",data[n%8]);
    return 0;
}
