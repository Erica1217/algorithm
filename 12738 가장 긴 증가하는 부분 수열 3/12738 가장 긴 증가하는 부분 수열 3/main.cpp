//
//  main.cpp
//  12738 가장 긴 증가하는 부분 수열 3
//
//  Created by 김유진 on 2020/03/09.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> result;
int main()
{
    int n;
    int a;
    scanf("%d",&n);
    scanf("%d",&a);
    result.push_back(a);
    for(int i=1 ; i<n ; i++)
    {
        scanf("%d",&a);
        int lb = lower_bound(result.begin(),result.end(),a)-result.begin();
        int end = result.size()-1;
        if(result[end]<a)
        {
            result.push_back(a);
        }
        else
        {
            result[lb]=a;
        }
    }
    printf("%d",result.size());
}
