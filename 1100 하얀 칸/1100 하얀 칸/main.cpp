//
//  main.cpp
//  1100 하얀 칸
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    char data[10][10];
    
    for(int i=0 ; i<8 ; i++)
    {
        cin>>data[i];
    }
    
    int cnt=0;
    for(int i=0 ; i<8 ; i++)
    {
        for(int j=i%2 ; j<8 ; j+=2)
        {
            if(data[i][j]=='F')
                cnt++;
        }
    }
    cout<<cnt;
}
