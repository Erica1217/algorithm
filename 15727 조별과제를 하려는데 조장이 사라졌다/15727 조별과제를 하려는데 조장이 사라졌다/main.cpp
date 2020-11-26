//
//  main.cpp
//  15727 조별과제를 하려는데 조장이 사라졌다
//
//  Created by 김유진 on 2020/08/30.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int result = n/5;
    result += n%5==0?0:1;
    printf("%d",result);
}
