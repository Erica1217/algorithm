//
//  main.cpp
//  11723 집합
//
//  Created by 김유진 on 2020/07/27.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int check[30]={0,};
    int x;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        
        if(s == "add")
        {
            cin>>x;
            check[x]=1;
        }
        else if(s=="remove")
        {
            cin>>x;
            check[x]=0;
        }
        else if(s=="check")
        {
            cin>>x;
            cout<<check[x]<<"\n";
        }
        else if(s== "toggle")
        {
            cin>>x;
            check[x]=1-check[x];
        }
        else if(s=="all")
        {
            for(int i=1 ; i<=20 ; i++)
            {
               check[i]=1;
            }
        }
        else if(s=="empty")
        {
            for(int i=1 ; i<=20 ; i++)
            {
                check[i]=0;
            }
        }
    }
}
