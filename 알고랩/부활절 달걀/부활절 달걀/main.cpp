//
//  main.cpp
//  부활절 달걀
//
//  Created by 김유진 on 2020/03/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {
    int t;
    cin>>t;
    
    for(int i=0 ; i<t ;i++)
    {
        int y;
        cin>>y;
    
        int c= y/100;
        int n = y-(y/19*19);
        int T = (c-17)/25;
        int I =c-((c/4)+((c-T)/3)) + (n*19+15);
        int j=I-(I/30*30);
        int k = j-((j/28)*(1-(j/28))*(29/(j+1))*((21-n)/11));
        int l =y+(y/4)+j+2-c+(c/4);
        int p = l-(l/7)*7;
        int q = k-p;
        int m=(q+40)/44 +3;
        int day=(q+28)-(m/4*31);
        
        cout<<m<<" "<<day<<"\n";
    }
}
