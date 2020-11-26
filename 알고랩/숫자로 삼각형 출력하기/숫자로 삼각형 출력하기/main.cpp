//
//  main.cpp
//  숫자로 삼각형 출력하기
//
//  Created by 김유진 on 2020/03/30.
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
        int k;
        cin>>k;
        for(int i=1 ; i<=k ; i++)
        {
            int tmp = k;
            int x=i;
            for(int j=0 ; j<i ; j++)
            {
                cout<<x<<" ";
                x+=--tmp;
            }
            cout<<endl;
        }
    }
}
