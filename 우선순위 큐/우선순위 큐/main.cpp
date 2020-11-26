//
//  main.cpp
//  우선순위 큐
//
//  Created by 김유진 on 2020/05/01.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
typedef pair<ci, char> data;
struct sortf{
    bool operator() (data x, data y){
        if(x.second < y.second){
            return 0;
        }
        return 1;
    }
};

int main()
{
//    FILE * out = fopen("output.txt","w");
//    priority_queue<int> Q;
//    priority_queue<int, vector<int>, greater<int> > Q;
    priority_queue<int, vector<int> , sortf> Q;
    
    Q.push(1);
    Q.push(4);
    Q.push(2);
    Q.push(8);
    Q.push(5);
    Q.push(7);
    
    
    while(Q.size())
    {
        printf("%d",Q.top());
        Q.pop();
    }
    return 0;
}
