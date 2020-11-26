//
//  main.cpp
//  이동평균
//
//  Created by 김유진 on 2020/04/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    int n,k;
    int data[300]={0,};
    while(t--)
    {
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>data[i];
        }
        cin>>k;
        
        cout<<n-k+1<<" ";
        int sum=0;
        for(int i=0 ; i<k ; i++)
        {
            sum+=data[i];
        }
        cout<<sum/k<<" ";
        for(int i=k ; i<n ; i++)
        {
            sum-=data[i-k];
            sum+=data[i];
            cout<<sum/k<<" ";
        }
        cout<<"\n";
    }
}
