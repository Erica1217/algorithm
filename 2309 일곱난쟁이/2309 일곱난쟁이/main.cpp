//
//  main.cpp
//  2309 일곱난쟁이
//
//  Created by 김유진 on 13/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int input[10]={0,};
    int sum=0;
    for(int i=0 ; i< 9 ; i++)
    {
        scanf("%d",&input[i]);
        sum+=input[i];
    }
    sum-=100;
    sort(input,input+9);
    for(int i=0 ; i<9 ; i++)
    {
        for(int j=0 ; j<9 ; j++)
        {
            if(input[i]+input[j] == sum){
                for(int k=0 ; k<9 ; k++)
                {
                    if(i==k || j==k){
                        continue;
                    }
                    printf("%d\n",input[k]);
                }
                return 0;
            }
        }
    }
}
