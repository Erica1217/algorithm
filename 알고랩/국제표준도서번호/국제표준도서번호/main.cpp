//
//  main.cpp
//  국제표준도서번호
//
//  Created by 김유진 on 2020/05/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int t;
    const int MAX_LENGTH[5]={5,7,6,1};
    const int MULTIPLE[15]={10,9,8,7,6,5,4,3,2};
    cin>>t;
    while(t--)
    {
        char input[200]={0,};
        cin>>input;
        
        
        int number[220]={0,};
        int numberLength=0;
        int j=0;
        bool isISBN=true;
        for(int i=0 ; i<4 ; i++)
        {
            int length=0;
            while('0'<=input[j] && input[j]<='9')
            {
                length++;
                number[numberLength++] = input[j]-'0';
                j++;
            }
            if(i==3 && length==0 && input[j]=='X')
            {
                number[numberLength++]=-10;
                j++;
            }
            else if(input[j]!='\0' && input[j]!='-')
            {
                isISBN = false;
                break;
            }
            else if(length>MAX_LENGTH[i] || length==0)
            {
                isISBN=false;
                break;
            }
            j++;
        }
        
        j--;
//        cout<<input[j]<<"~~~ \n";
        if(input[j]!='\0' || numberLength!=10)
        {
            isISBN=false;
//            cout<<"\0\n";
        }
        
        int sum=0;
        for(int i=0 ; i<numberLength-1 ; i++)
        {
            if(number[i]<0)
            {
                isISBN=false;
            }
            sum+=number[i]*MULTIPLE[i];
//            cout<<number[i]<<" * "<<MULTIPLE[i]<<" "<<sum<<endl;
        }
        int checkSum=((sum/11)+1)*11 - sum;
        if(checkSum==11)
        {
            checkSum=0;
        }
//        cout<<sum<<" "<<checkSum<<endl;
        if( !(checkSum == number[numberLength-1]) && !(checkSum==10 && input[j-1]=='X'))
        {
            isISBN=false;
//            cout<<checkSum<<" "<<input[j-2]<<"  checkSum\n";
        }
        
        
        if(isISBN)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
    }
}
