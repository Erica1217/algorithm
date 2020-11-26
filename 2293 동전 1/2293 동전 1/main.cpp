//
//  main.cpp
//  2293 동전 1
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    int input[200]={0,};
    int data[10100]={0,};

    
    scanf("%d %d",&n,&k);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    data[0]=1;
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=input[i]; j<=k ; j++)
        {
            data[j] += data[j-input[i]];
        }
    }
    
    printf("%d", data[k]);
}
