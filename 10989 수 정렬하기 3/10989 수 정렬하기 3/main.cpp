//
//  main.cpp
//  10989 수 정렬하기 3
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int data[11000]={0,};
int main()
{
    int n;
    scanf("%d",&n);
    
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        data[a]++;
    }
    for(int i=1 ; i<=10000 ; i++)
    {
        for(int j=0 ; j<data[i] ; j++)
        {
            printf("%d\n",i);
        }
    }
}
