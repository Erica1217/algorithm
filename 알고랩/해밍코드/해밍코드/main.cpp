//
//  main.cpp
//  해밍코드
//
//  Created by 김유진 on 2020/05/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

int paritBit[5] = {1,2,4,8,16};

void print2(unsigned int n)
{
    int bin[50]={0,};
    int i=0;
    while(n!=0)
    {
          bin[i++] = n%2;
          n/=2;
    }
    for(int j=i-1 ; j>=0 ; j--)
    {
        cout<<bin[j];
    }
    cout<<endl;
}

unsigned int getSendData(unsigned int n)
{
    unsigned int result=0;
    int i=1, j=0;
    while(n!=0)
    {
       if(j<5 && paritBit[j]==i)
       {
           i++; j++;
           continue;
       }
        result = result | (n%2<<(i-1));
        n/=2;
        i++;
    }
    
    for(int i=0 ; i<5 ; i++)
    {
        int p = paritBit[i];
        int bit1Num=0;
        for(int j=paritBit[i]-1 ; j<32 ; j+=(p*2))
        {
            for(int k=j ; k<j+p ; k++)
            {
                bit1Num+=(result>>k)%2;
            }
        }
        result = (result | (bit1Num%2<<(p-1)));
    }
    
    return result;
}

unsigned int getRealData(unsigned int n)
{
    int errorBit=0;
    for(int i=0 ; i<5 ; i++)
    {
        int p = paritBit[i];
        int bit1Num=0;
        for(int j=paritBit[i]-1 ; j<32 ; j+=(p*2))
        {
            for(int k=j ; k<j+p ; k++)
            {
                bit1Num+=(n>>k)%2;
            }
        }
        if(bit1Num%2==1)
        {
            errorBit+=p;
        }
    }
    if(errorBit!=0)
    {
        int errorNum = (n>>(errorBit-1))%2;
        if(errorNum==1)
        {
            n-=(1<<(errorBit-1));
        }
        else
        {
            n+=(1<<(errorBit-1));
        }
    }
    int result=0;
    int i=0,j=0,num=0;
    while(n!=0)
    {
        num++;
        if(paritBit[j] == num)
        {
            j++;
            n/=2;
            continue;
        }
        result +=(n%2<<i);
        n/=2;
        i++;
    }
    return result;
}

int main()
{
    int t;
    int k,n;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        if(k==0)
        {
            cout<<getSendData(n)<<"\n";
        }
        else if(k==1)
        {
            cout<<getRealData(n)<<"\n";
        }
    }
}
