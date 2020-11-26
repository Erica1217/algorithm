//
//  main.cpp
//  1766 문제집
//
//  Created by 김유진 on 2020/05/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int in[33000]={0,};
int check[33000]={0,};
vector<int> out[33000];


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
    
    for(int a=0 ; a<n ; a++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(in[i]==0 && check[i]==0)
            {
                check[i]=1;
                for(int j=0 ; j<out[i].size() ; j++)
                {
                    in[out[i][j]]--;
                }
                printf("%d ",i);
                break;
            }
        }
    }
    
}
