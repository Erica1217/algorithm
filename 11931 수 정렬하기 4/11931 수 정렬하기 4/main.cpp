//
//  main.cpp
//  11931 수 정렬하기 4
//
//  Created by 김유진 on 27/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<int> data;

int main()
{
    scanf("%d",&n);
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        data.push_back(a);
        
    }
    sort(data.begin(),data.end(),greater<int>());
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d\n",data[i]);
    }
}
