//
//  main.cpp
//  1849 순열
//
//  Created by 김유진 on 2020/07/19.
//  Copyright © 2020 김유진. All rights reserved.
//
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n );
    int input[110000]={0,};
    vector<int> v;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
        v.push_back(i);
    }
    
    int result[110000]={0,};
    for(int i=0; i<n ; i++)
    {
        result[v[input[i]]]=i+1;
        v.erase(v.begin()+input[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        printf("%d\n",result[i]);
    }
}
