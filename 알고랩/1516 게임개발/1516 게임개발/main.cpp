//
//  main.cpp
//  1516 게임개발
//
//  Created by 김유진 on 2020/05/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
int in[600]={0,};
int check[600]={0,};
int t[600]={0,};
int result[600]={0,};
vector<int> out[33000];

using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&t[i]);
        result[i]=t[i];
        int first=0;
        while(first!=-1)
        {
            scanf("%d",&first);
            if(first==-1)
            {
                break;
            }
            in[i]++;
            out[first].push_back(i);
        }
        
    }
    
    for(int a=1 ; a<=n ; a++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(check[i]==0 && in[i]==0)
            {
                check[i]=1;
                for(int j=0 ; j<out[i].size(); j++)
                {
                    in[out[i][j]]--;
                    if(result[out[i][j]] < result[i]+t[out[i][j]])
                    {
                        result[out[i][j]] = result[i]+t[out[i][j]];
                    }
                }
                break;
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        printf("%d\n",result[i]);
    }
}
