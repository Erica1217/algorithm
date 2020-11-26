//
//  main.cpp
//  직선그래프출력하기
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
    for(int a=0; a<t; a++)
    {
        int k;
        cin>>k;
        for(int i=0 ; i<k ; i++)
        {
            for(int j=0 ; j<k ; j++)
            {
                if(i==k/2 && j==k/2)
                {
                    cout<<"O";
                }
                else if(i==k/2)
                {
                    cout<<"+";
                }
                else if(j==k/2)
                {
                    cout<<"I";
                }
                else if(i+j ==k-1)
                {
                    cout<<"*";
                }
                else{
                    cout<<".";
                }
            }
            cout<<endl;
        }
    }
}
