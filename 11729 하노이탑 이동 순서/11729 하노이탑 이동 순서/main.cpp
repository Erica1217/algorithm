//
//  main.cpp
//  11729 하노이탑 이동 순서
//
//  Created by 김유진 on 2020/01/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int N;
void hanoi(int n,int start,int mid, int end)
{
    if(n==1)
    {
        printf("%d %d\n",start, end);
        return;
    }
    hanoi(n-1, start, end, mid);
    printf("%d %d\n",start, end);
    hanoi(n-1, mid, start, end);
}


int main()
{
    scanf("%d",&N);
    printf("%d\n",(1<<N)-1);
    hanoi(N,1,2,3);
}
