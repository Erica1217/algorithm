//
//  main.cpp
//  13549 숨바꼭질 3
//
//  Created by 김유진 on 29/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;
typedef pair<int,int> p; // int location,int  time
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    deque<p> data;
    int check[110000]={0,};
    
    data.push_back(p(N,0));
    check[N]=1;
    while(!data.empty())
    {
        int location= data.front().first;
        int time = data.front().second;
        
        data.pop_front();
        if(location == K)
        {
            printf("%d",time);
            return 0;
        }
        
        if(location*2<=100000 && check[location*2]==0)
        {
            data.push_front(p(location*2,time));
            check[location*2]=1;
        }
        if(location-1 >=0 && check[location-1]==0)
        {
            data.push_back(p(location-1,time+1));
            check[location-1]=1;
        }
        if(location+1 <=100000 && check[location+1]==0)
        {
            data.push_back(p(location+1,time+1));
            check[location+1]=1;
        }
    }
}
