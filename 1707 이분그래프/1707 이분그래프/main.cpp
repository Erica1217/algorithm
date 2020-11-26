//
//  main.cpp
//  1707 이분그래프
//
//  Created by 김유진 on 2020/03/07.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
vector<int> data[30000];
int check[30000]={0,};
int v,e;
bool isBipartite=true;

void func(int start, int num)
{
    for(int i=0 ; i<data[start].size() ; i++)
    {
        int t =  data[start][i];
        if(check[t]==0)
        {
            int a = num==1?2:1;
            check[t] =a;
            func(t,a);
        }
        else if(check[t]==num)
        {
            isBipartite=false;
            return;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    
    for(int a=0; a<T ;a++)
    {
        scanf("%d %d",&v,&e);
        int v1,v2;
        for(int i=0 ; i<e ; i++)
        {
            scanf("%d %d",&v1,&v2);
            data[v1].push_back(v2);
            data[v2].push_back(v1);
        }
        for(int i=1 ; i<=v ; i++)
        {
            if(check[i]==0)
            {
                check[i]=1;
                func(i,1);
            }
        }
        printf(isBipartite?"YES\n":"NO\n");
        for(int i=0 ; i<=v ; i++)
        {
            data[i].clear();
            check[i]=0;
        }
        isBipartite=true;
    }
    return 0;
}
