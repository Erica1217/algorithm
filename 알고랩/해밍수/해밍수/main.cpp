//
//  main.cpp
//  해밍수
//
//  Created by 김유진 on 2020/04/21.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1000000000;
vector<int> data;
int d[5]={2,3,5};
int num=0;
void func(int before,int ret)
{
    if(ret*2>=MAX)
    {
        return;
    }
    data.push_back(ret);
    num++;
    for(int i=before ; i<3 ; i++)
    {
        if((long long)ret*(long long)d[i]<MAX)
            func(i,ret*d[i]);
    }
}

int main()
{
    int n;
    cin>>n;
    func(0,1);
    sort(data.begin(),data.end());
    int input;
    for(int i=0 ; i<n ; i++)
    {
        cin>>input;
        cout<<data[input-1]<<"\n";
    }
}
