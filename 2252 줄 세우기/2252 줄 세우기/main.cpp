//
//  main.cpp
//  2252 줄 세우기
//
//  Created by 김유진 on 2020/05/02.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> out[33000];
int check[33000]={0,};
int in[33000]={0,};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a,b;
    while(m--)
    {
        scanf("%d %d",&a,&b);
        in[b]++;
        out[a].push_back(b);
    }
    
    int curr=0;
    while(curr!=-1)
    {
        curr=-1;
        for(int i=1 ; i<=n ; i++)
        {
            if(check[i]==0 && in[i]==0)
            {
                check[i]=1;
                for(int j=0 ; j<out[i].size() ; j++)
                {
                    in[out[i][j]]--;
                }
                curr=i;
                printf("%d ",i);
                break;
            }
        }
    }
}
