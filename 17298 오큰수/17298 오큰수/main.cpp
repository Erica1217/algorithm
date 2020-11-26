//
//  main.cpp
//  17298 오큰수
//
//  Created by 김유진 on 2020/08/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n;
    int result[1100000]={0,};
    int top=0;
    vector<pair<int, int> > data(1100000);
    scanf("%d",&n);
    int a;
    for(int i=0; i<n ; i++)
    {
        scanf("%d",&a);
        while(top!=0 && data[top-1].first<a)
        {
            int idx = data[--top].second;
            result[idx]=a;
        }
        data[top++] = make_pair(a, i);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        if(result[i]==0)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", result[i]);
        }
    }
}
