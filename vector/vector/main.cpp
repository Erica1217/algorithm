//
//  main.cpp
//  vector
//
//  Created by 김유진 on 26/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    for(int i=0 ; i<v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    v.clear();
    for(int i=0 ; i<v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}
