//
//  main.cpp
//  16194 카드 구매하기2
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    int input[1010]={0,};
    int data[1010]={0,};
    cin>>n;
    
    for(int i=1 ; i<=n ; i++)
    {
        cin>>input[i];
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=i ; j<=n ; j++)
        {
            if(data[j]==0 || data[j-i] + input[i] < data[j])
            {
                data[j] = data[j-i]+input[i];
            }
        }
    }
    cout<<data[n];
}
