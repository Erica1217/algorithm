//
//  main.cpp
//  4673 셀프 넘버
//
//  Created by 김유진 on 29/07/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int data[10010]={0,};
    int n = 10000;
    for(int i=1 ; i<=n ; i++)
    {
        int sum = i;
        int a= i;
        while (a!=0){
            sum += a%10;
            a/=10;
        }
        if(sum<=10000)
            data[sum]=1;
    }
    
    for(int i=1 ; i<=n ; i++){
        if(data[i]==0){
            printf("%d\n",i);
        }
    }
}
