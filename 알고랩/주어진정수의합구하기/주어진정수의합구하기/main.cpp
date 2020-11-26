//
//  main.cpp
//  주어진정수의합구하기
//
//  Created by 김유진 on 2020/03/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=0 ; i<T ; i++)
    {
        int n;
        cin>>n;
        int sum=0;
        int input;
        for(int j=0 ; j<n ; j++)
        {
            cin>>input;
            sum+=input;
        }
        cout<<sum<<"\n";
    }
}
