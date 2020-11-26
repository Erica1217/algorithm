//
//  main.cpp
//  사각형과 점과의 거리
//
//  Created by 김유진 on 2020/04/06.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
int abs(int n)
{
    return n<0?n*-1:n;
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    int dotX, dotY;
    for(int i=0 ; i<t ; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cin>>dotX>>dotY;
        
        int d2 = 999999999;
        int d1 = 999999999;
        
        
        if(x1<= dotX && dotX<=x2 &&
           y1<= dotY && dotY<=y2)
        {
            d2=0;
            d1=0;
        }
        for(int i=x1 ; i<=x2 ; i++)
        {
            for(int j=y1 ; j<=y2 ; j++)
            {
                int a= (i-dotX)*(i-dotX);
                int b= (j-dotY)*(j-dotY);
                if(d1>(a+b))
                {
                    d1=(a+b);
                }
                
                int c = abs(i-dotX)+abs(j-dotY);
                if(d2>c)
                {
                    d2=c;
                }
            }
        }
        cout<<d1<<" "<<d2<<"\n";
    }
}
