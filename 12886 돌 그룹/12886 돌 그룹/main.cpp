//
//  main.cpp
//  12886 돌 그룹
//
//  Created by 김유진 on 2020/03/08.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int check[1600][1600]={0,};

int main()
{
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    
    deque<vector<int>> q;
    vector<int> t;
    t.push_back(A);
    t.push_back(B);
    t.push_back(C);
    if((A+B+C)%3 != 0)
    {
        printf("0");
        return 0;
    }
    
    q.push_back(t);
    while(!q.empty())
    {
        vector<int> d = q.front();
        sort(d.begin(), d.end());
        
        if(d[0] == d[1] && d[1] == d[2])
        {
            printf("1");
            return 0;
        }
        
        if(d[0]!= d[1])
        {
            vector<int> tmp;
            tmp.push_back(d[1]-d[0]);
            tmp.push_back(d[0]*2);
            tmp.push_back(d[2]);
            sort(tmp.begin(), tmp.end());
            if(check[tmp[0]][tmp[2]] == 0)
            {
                check[tmp[0]][tmp[2]]=1;
                q.push_back(tmp);
            }
        }
        if(d[0]!=d[2])
        {
            vector<int> tmp;
            tmp.push_back(d[2]-d[0]);
            tmp.push_back(d[0]*2);
            tmp.push_back(d[1]);
            sort(tmp.begin(), tmp.end());
            if(check[tmp[0]][tmp[2]] == 0)
            {
                check[tmp[0]][tmp[2]]=1;
                q.push_back(tmp);
            }
        }
        if(d[1]!=d[2])
        {
            vector<int> tmp;
            tmp.push_back(d[2]-d[1]);
            tmp.push_back(d[1]*2);
            tmp.push_back(d[0]);
            sort(tmp.begin(), tmp.end());
            if(check[tmp[0]][tmp[2]] == 0)
            {
                check[tmp[0]][tmp[2]]=1;
                q.push_back(tmp);
            }
        }
        q.pop_front();
    }
    printf("0");
    return 0;
}
