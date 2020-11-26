//
//  main.cpp
//  10993 별 찍기 -18
//
//  Created by 김유진 on 21/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
char data[3000][2000]={0,};

void func(int x,int y,int n,int m, bool triangle)
{
    if(m==1)
    {
        data[x][y]='*';
        return;
    }
    
    if(triangle)
    {
        
//        func(,!triangle);
    }
    else
    {
    
//        func(0,-1,0,-1,!triangle);
    }
}

int main()
{
    int input;
    cin>>input;
    int m=1;
    int n=1;
    for(int i=0 ; i<input-1 ; i++)
    {
        m = m*2 +3;
        n = n*2 +1;
    }
    
    cout<<n-1<<" "<<m/2<<endl;
    func(n-1,m/2,n,m,input%2==0);
    
    for(int i=0 ; i<n ; i++)
    {
        cout<<data[i];
    }
    
    cout<<n<<" "<<m;
}
