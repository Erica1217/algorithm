//
//  main.cpp
//  2579 계단 오릑
//
//  Created by 김유진 on 13/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int max(int a, int b){
    return a>b ? a:b;
}

int main()
{
    int n;
    int input[400]={0,};
    int data[400][3]={0,};
    
    scanf("%d",&n);
    for(int i= 0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    data[0][0]=input[0];
    data[0][1]=0;
    
    data[1][0]=input[0]+input[1];
    data[1][1]=input[1];
    
    for(int i=2 ; i<n ; i++)
    {
        data[i][0] = data[i-1][1] + input[i];
        data[i][1] = max(data[i-2][0], data[i-2][1]) + input[i];
    }
    
    int result = max(data[n-1][0], data[n-1][1]);
    
    printf("%d" ,result);
}
