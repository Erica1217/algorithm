//
//  main.cpp
//  끝자리정수계산하기
//
//  Created by 김유진 on 2020/03/30.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    for(int i=0 ; i<t ; i++)
    {
        int n;
        cin >>n;
        
        char data[40]={0,};
        int result=1;
        for(int j=0 ; j<n ; j++)
        {
            cin>>data;
            result*=(data[strlen(data)-1]-'0');
            result%=10;
        }
        cout<<result<<endl;
    }
}
