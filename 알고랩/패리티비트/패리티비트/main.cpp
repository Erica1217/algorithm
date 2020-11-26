//
//  main.cpp
//  패리티비트
//
//  Created by 김유진 on 2020/04/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int a=0 ; a<t; a++)
    {
        long long n;
        cin>>n;
        long long tmp=n;
        int num1=0;
        while(tmp){
            num1+=tmp%2;
            tmp/=2;
        }
//        cout<<num1<<" ";
        if(num1%2==1)
        {
            n+=(long long)(1u<<31);
        }
        cout<<n<<endl;
    }
}
