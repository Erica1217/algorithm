//
//  main.cpp
//  11047 동전 0
//
//  Created by 김유진 on 2020/01/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    
    int data[50]={0,};
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    int result;
    int i=n;
    i--;
    do{
        result+= k/data[i];
        k=k%data[i];
        i--;
    }while(k!=0);
    
    printf("%d",result);
}
