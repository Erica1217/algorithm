//
//  main.cpp
//  마에스트로 1
//
//  Created by 김유진 on 2020/03/14.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

using namespace std;
int main()
{
    int n;
//    int number[15]={6,2,5,5,4,5,6,3,7,6};
    scanf("%d",&n);
    if(n%2==1)
    {
        printf("7");
        n-=3;
    }
    for(int i=0 ; i<n/2 ; i++)
    {
        printf("1");
    }
}
