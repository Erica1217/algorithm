//
//  main.cpp
//  2611 자동차 경주
//
//  Created by 김유진 on 2020/05/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <deque>
using namespace std;
vector<int> data[1010];
int value[1010][1010]={0,};
int pass[1010]={0,};
int score[1010]={0,};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    int p,q,r;
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&p,&q,&r);
        data[p].push_back(q);
        value[p][q]=r;
    }
    
    deque<int> queue;
    queue.push_back(1);
    int start;
    while(!queue.empty())
    {
        start = queue.front();
        for(int j=0 ; j<data[start].size() ; j++)
        {
            int dest = data[start][j];
            if(score[dest]< score[start] + value[start][dest])
            {
                score[dest] = score[start] + value[start][dest];
                pass[dest]=start;
                if(dest!=1)
                    queue.push_back(dest);
            }
        }
        queue.pop_front();
    }
    
    int result[1010]={0,};
    
    int s=pass[1];
    int resultNum=0;
    while(s!=1)
    {
        result[resultNum++] = s;
        s=pass[s];
    }
    printf("%d\n",score[1]);
    
    printf("1 ");
    for(int i=resultNum-1 ; i>=0 ; i--)
    {
        printf("%d ",result[i]);
    }
    printf("1");
}
