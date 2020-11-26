//
//  main.cpp
//  수직 수평선분의 교차
//
//  Created by 김유진 on 2020/04/08.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    int verX,verY1,verY2;
    int horY, horX1, horX2;
    int x1,y1,x2,y2;
    cin>>t;
    for(int i=0 ; i<t ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2)
            {
                verX = x1;
                verY1 = y1<y2?y1:y2;
                verY2 = y1>y2?y1:y2;
            }
            if(y1==y2)
            {
                horY=y1;
                horX1 = x1<x2?x1:x2;
                horX2 = x1>x2?x1:x2;
            }
        }
        
//        cout<<"*"<<verX<<" "<<verY1<<" "<<verY2<<endl;
//        cout<<"*"<<horY<<" "<<horX1<<" "<<horX2<<endl;
        if(((verX==horX1 || verX==horX2) && (verY1<=horY && horY<=verY2))||
           ((horY == verY1 || horY == verY2)&&(horX1<=verX && verX<=horX2)))
        {
            cout<<"2\n";
        }
        else if(horX1<verX && verX<horX2 && verY1<horY && horY<verY2)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
    }
}
