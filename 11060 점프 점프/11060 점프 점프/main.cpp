//
//  main.cpp
//  11060 점프 점프
//
//  Created by 김유진 on 2020/03/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;
int main()
{
    int n;
    int data[1010]={0,};
    int check[1010]={0,};
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    deque<pair<int,int>> queue;
    queue.push_back(make_pair(0,0));
    
    while(!queue.empty())
    {
        int crt = queue.front().first;
        int num = queue.front().second;
        
        if(crt==n-1)
        {
            printf("%d",num);
            return 0;
        }
        
        for(int i=1; i<=data[crt] ; i++)
        {
            if(crt+i<n && check[crt+i]==0)
            {
                check[crt+i]=1;
                queue.push_back(make_pair(crt+i,num+1));
            }
        }
        queue.pop_front();
    }
    printf("-1");
}
