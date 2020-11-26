//
//  main.cpp
//  2623 음악 프로그램
//
//  Created by 김유진 on 2020/05/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int in[1010]={0,};
vector<int> out[1010];
int check[1010][1010]={0,};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i=0 ; i<m ; i++)
    {
        int mm;
        scanf("%d",&mm);
        int a;
        int before=-1;
        for(int j=0 ; j<mm ; j++)
        {
            scanf("%d",&a);
            if(before!=-1 && check[before][a]==0) // out
            {
                out[before].push_back(a);
                in[a]++;
                check[before][a]=1;
            }
            before=a;
        }
    }
    
    int inCheck[1010]={0,};
    
    int result[1010]={0,};
    for(int i=0 ; i<n ; i++)
    {
        int cur=0;
        for(int j=1 ; j<=n ; j++)
        {
            if(inCheck[j]==0 && in[j]==0)
            {
                cur=j;
                inCheck[j]=1;
                break;
            }
        }
        if(cur==0)
        {
            printf("0");
            return 0;
        }
        
        for(int j=0; j<out[cur].size() ; j++)
        {
            in[out[cur][j]]--;
        }
        result[i]=cur;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d\n",result[i]);
    }
        
    
    
//    for(int i=1 ; i<=n ; i++)
//    {
//        printf("%d %d ",i,in[i]);
//        for(int j=0 ; j<out[i].size() ; j++)
//        {
//            printf("%d ",out[i][j]);
//        }
//        printf("\n");
//    }
}

