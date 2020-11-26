//
//  main.cpp
//  9095 1, 2, 3 더하기
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int max=0;
    int input[100]={0,};
    for(int i=0 ; i<n ; i++)
    {
        cin>>input[i];
        if(max < input[i])
        {
            max=input[i];
        }
    }
    
    int data[20]={0,};
    data[1]= 1;
    data[2] = 2;
    data[3] = 4;
    for(int i=4 ; i<=max ; i++)
    {
        data[i] = data[i-1]+data[i-2]+data[i-3];
    }
    
    for(int i=0 ; i<n ; i++)
    {
        cout<<data[input[i]]<<endl;
    }
        
}
