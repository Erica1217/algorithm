//
//  main.cpp
//  11070 피타고라스 기댓값
//
//  Created by 김유진 on 17/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=0 ; i<t; i++)
    {
        int n,m;
        int data[3][1010]={0,};//[0][] 총 득점수, //[1][] 총 실점수
        int a, b, p ,q;
        cin>>n>>m;
        for(int j=0 ; j<m ; j++)
        {
            cin>>a>>b>>p>>q;
            data[0][a]+=p;
            data[1][b]+=p;
            data[0][b]+=q;
            data[1][a]+=q;
        }
        
        int W[1010];
        int max=0,min=1000;
        for(int j=1 ; j<=n ; j++)
        {
            int S = data[0][j];
            int A = data[1][j];
            
            double d = (S==0 && A==0) ? 0 : (double)(S*S)/(S*S + A*A);
            W[j] = (double)(d*1000);
            
            if(max<W[j])
            {
                max=W[j];
            }
            if(min>W[j])
            {
                min=W[j];
            }
        }
        cout<<max<<"\n"<<min<<"\n";
    }
}
