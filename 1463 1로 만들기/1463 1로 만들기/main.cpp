//
//  main.cpp
//  1463 1로 만들기
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
int check[1100000]={0,};
int data[1100000]={0,};
int value[1100000]={0,};

using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int start=0,end=0;
    
    data[end]=n;
    check[n]=1;
    value[end]=0;
    end++;
    
    while(start!=end)
    {
        int d = data[start];
        int v = value[start];
        
        if(d==1)
        {
            cout<<v;
        }
        
        if(d%3==0 && check[d/3]==0)
        {
            int a=d/3;
            data[end]=a;
            check[a]=1;
            value[end]=v+1;
            end++;
        }
        
        if(d%2==0 && check[d/2]==0)
        {
            int a=d/2;
            data[end]=a;
            check[a]=1;
            value[end]=v+1;
            end++;
        }
        
        if(d-1>0 && check[d-1]==0)
        {
            int a=d-1;
            data[end]=a;
            check[a]=1;
            value[end]=v+1;
            end++;
        }
        start++;
    }
    
}
