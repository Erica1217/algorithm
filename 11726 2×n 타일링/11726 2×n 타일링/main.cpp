//
//  main.cpp
//  11726 2×n 타일링
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
    int data[1010]={0,};
    
    data[1]=1;
    data[2]=2;
    
    for(int i=3; i<=n ; i++)
    {
        data[i] = (data[i-1]+data[i-2])%10007;
    }
    cout<<data[n];
}
