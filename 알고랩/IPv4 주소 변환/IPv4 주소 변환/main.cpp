//
//  main.cpp
//  IPv4 주소 변환
//
//  Created by 김유진 on 2020/05/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    
    int k;
    while(t--)
    {
        cin>>k;
        if(k==1)
        {
            char input[30]={0,};
            cin>>input;
            unsigned int result=0;
            int j=0;
            for(int i=0 ; i<4 ; i++)
            {
                int num=0;
                while(input[j]!='.' && input[j]!='\0')
                {
                    num*=10;
                    num+=input[j]-'0';
                    j++;
                }
                j++;
                result = result<<8;
                result+=num;
            }
            
            cout<<result<<"\n";
        }
        else if(k==2)
        {
            unsigned int input;
            const unsigned int NUM_255 = 255; // 00000000 00000000 00000000 11111111
            unsigned int result[10]={0,};
            cin>>input;
            for(int i=3; i>=0 ; i--)
            {
                result[i] = input & NUM_255;
                input = input>>8;
            }
            for(int i=0 ; i<4 ; i++)
            {
                cout<<result[i];
                if(i!=3)
                {
                    cout<<".";
                }
            }
            cout<<"\n";
        }
    }
}
