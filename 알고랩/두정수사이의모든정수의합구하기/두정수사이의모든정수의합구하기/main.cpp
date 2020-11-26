//
//  main.cpp
//  두정수사이의모든정수의합구하기
//
//  Created by 김유진 on 2020/03/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0 ; i<t ; i++)
    {
        int m,n;
        cin>>m>>n;
        int sum=(m+n)*(n-m+1)/2;
        cout<<sum<<"\n";
    }
    return 0;
}
