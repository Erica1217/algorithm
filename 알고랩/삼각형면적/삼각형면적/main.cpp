//
//  main.cpp
//  삼각형면적
//
//  Created by 김유진 on 2020/04/08.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

int direction(int n)
{
    return n<0?-1:n==0?0:1;
}

int abs(int n)
{
    return n<0?-1*n:n;
}

int main()
{
    int t;
    cin>>t;
    int ax,ay,bx,by,cx,cy;
    for(int i=0 ; i<t ; i++)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        int sinedArea = (((bx-ax)*(cy-ay))-((cx-ax)*(by-ay)));
        cout<<abs(sinedArea)<<" "<<direction(sinedArea)<<"\n";
    }
}
