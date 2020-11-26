//
//  main.cpp
//  10991 별 찍기 - 16
//
//  Created by 김유진 on 21/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<i ; j++)
        {
            printf(" ");
        }
        
        for(int j=0 ; j<n-i ; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
