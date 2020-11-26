//
//  main.cpp
//  집합연산
//
//  Created by 김유진 on 2020/04/21.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
const int BIT_SIZE=32;
void print(unsigned int group[])
{
    int num=0;
    
    unsigned int g;
    for(int i=0 ; i<5 ; i++)
    {
        g=group[i];
        while(g!=0)
        {
            num+=g%2;
            g/=2;
        }
    }
    
    cout<<num<<" ";
    int number=0;
    for(int i=0 ; i<5 ; i++)
    {
        g=group[i];
        number=BIT_SIZE*i;
        while(g!=0)
        {
            if(g%2==1)
            {
                cout<<number<<" ";
            }
            number++;
            g/=2;
        }
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0 ; i<t ;i++)
    {
        int a,b;
        unsigned int group_a[10]={0,};
        unsigned int group_b[10]={0,};
        int n,m;
        cin>>n;
        for(int j=0 ; j<n ; j++)
        {
            cin>>a;
            group_a[a/BIT_SIZE]+=1<<a%BIT_SIZE;
        }
        cin>>m;
        for(int j=0 ; j<m ; j++)
        {
            cin>>b;
            group_b[b/BIT_SIZE]+=1<<b%BIT_SIZE;
        }
        unsigned int group_n[10]={0,};
        unsigned int group_u[10]={0,};
        unsigned int group_m[10]={0,};
        for(int j=0 ; j<5 ; j++)
        {
            group_n[j] = group_a[j] & group_b[j];
            group_u[j] = group_a[j] | group_b[j];
            group_m[j] = group_u[j] - group_b[j];
        }

        print(group_n);
        print(group_u);
        print(group_m);
        
    }
    
}
