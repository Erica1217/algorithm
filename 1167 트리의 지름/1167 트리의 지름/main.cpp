//
//  main.cpp
//  1167 트리의 지름
//
//  Created by 김유진 on 2020/09/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int check[110000]={0,};
vector<pair<int, int> > data[110000];
int v;
int result=0;
int node1;
void func(int s, int sum)
{
    for(int i=0 ; i<data[s].size() ; i++)
    {
        int e = data[s][i].first;
        int d = data[s][i].second;
        if(check[e] == 0 )
        {
            check[e]=1;
            if(result<sum+d)
            {
                result = sum+d;
                node1=e;
            }
            func(e, sum+d);
        }
    }
}

int main()
{
    scanf("%d",&v);
    for(int i=0 ; i<v ; i++)
    {
        int v1,v2,d;
        scanf("%d",&v1);
        do{
            scanf("%d",&v2);
            if(v2==-1)
            {
                break;
            }
            scanf("%d",&d);
            data[v1].push_back(make_pair(v2,d));
        }while(true);
    }
    check[1]=1;
    func(1,0);
    for(int i=1 ; i<=v ; i++)
    {
        check[i]=0;
    }
    check[node1]=1;
    func(node1,0);
    printf("%d\n",result);
}
