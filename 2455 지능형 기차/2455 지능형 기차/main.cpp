//
//  main.cpp
//  2455 지능형 기차
//
//  Created by 김유진 on 02/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//


#include <stdio.h>
int main()
{
    int n=4;
    int data[10]={0,};
    int input[10][2]={0,};
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&input[i][0], &input[i][1]);
    }
    
    data[0] = input[0][1];
    int max = data[0];
    for(int i=1 ; i<n ; i++)
    {
        data[i] = data[i-1] - input[i][0] + input[i][1];
        if(max < data[i]){
            max = data[i];
        }
    }
    printf("%d",max);
}
