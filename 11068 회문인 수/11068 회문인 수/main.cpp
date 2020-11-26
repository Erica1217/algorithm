//
//  main.cpp
//  11068 회문인 수
//
//  Created by 김유진 on 18/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0 ; i<n; i++)
    {
        int input;
        cin>>input;
        for(int j=2 ; j<=64 ; j++)
        {
            int digit = input;
            int data[50]={0,};
            int digitsNum=0;
            while(digit!=0)
            {
                data[digitsNum++] = digit%j;
                digit/=j;
            }
            int isPalindrome=true;
            for(int k=0 ; k<digitsNum/2 ; k++)
            {
                if(data[k] != data[digitsNum-k-1])
                {
                    isPalindrome=false;
                    break;
                }
            }
            if(isPalindrome)
            {
                cout<<"1\n";
                break;
            }
            else if(!isPalindrome && j==64)
            {
                cout<<"0\n";
            }
        }
    }
}
