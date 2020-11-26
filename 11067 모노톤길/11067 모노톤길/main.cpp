//
//  main.cpp
//  11067 모노톤길
//
//  Created by 김유진 on 20/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Location{
    int x;
    int y;
};

bool Compare(const Location loc1, const Location loc2)
{
    return loc1.x < loc2.x;
}

int main()
{
    int T;
    cin>>T;
    
    for(int t=0 ; t<T ; t++)
    {
        int n;
        vector<Location> data;
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            Location loc;
            cin>>loc.x>>loc.y;
            data.push_back(loc);
        }
        
        sort(data.begin(),data.end(),Compare);
        
        cout<<"----------------------------\n";
        for(int i=0 ; i<n ; i++)
        {
            cout<<data[i].x<<" "<<data[i].y<<"\n";
        }
    }
}
