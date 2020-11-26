//
//  main.cpp
//  3111 검열
//
//  Created by 김유진 on 2020/04/03.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <deque>

using namespace std;

int main()
{
    char a[30];
    char input[310000];
    int check[310000]={0,};
    scanf("%s",a);
    scanf("%s",input);
    
    deque<char> left;
    deque<char> right;
    int an = strlen(a);
    int inputN = strlen(input);
    int start=0;
    int end=inputN;
    
    bool isLeft=true;
    while(true)
    {
        if(isLeft)
        {
            left
        }
    }
}
