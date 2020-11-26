//
//  main.cpp
//  다각형 면적
//
//  Created by 김유진 on 2020/04/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

int abs(int a){
    return a<0?a*-1:a;
}
int main()
{
    int t;
    cin>>t;
    
    for(int a=0; a<t ; a++)
    {
        int n;
        int x[200], y[200];
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>x[i]>>y[i];
        }
        
        int area=0;
        for(int i=0 ; i<n; i++)
        {
            area+=(x[i]+x[(i+1)%n])*(y[(i+1)%n]-y[i]);
        }
        cout<<abs(area)<<" ";
        if(area>0){
            cout<<1;
        }else{
            cout<<-1;
        }
        cout<<endl;
           
    }
}
