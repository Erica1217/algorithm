//
//  main.cpp
//  최단 경로
//
//  Created by 김유진 on 25/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue <pair<int,int>> q;
    int x,y;
    char z;
    
    q.push(make_pair(2,10));
    q.push(make_pair(3,11));
    q.push(make_pair(4,12));
    q.push(make_pair(5,13));
    q.push(make_pair(6,14));
    
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        
        cout<<x<<' '<<y<<'\n';
        q.pop();
    }
    
    cout<<"========================================"<<"\n";
    
    typedef pair <int, char> ci;
    queue<pair<int,ci>> Q;
    
    Q.push(make_pair(1,ci(10,'A')));
    Q.push(make_pair(2,ci(20,'B')));
    Q.push(make_pair(3,ci(30,'C')));
    Q.push(make_pair(4,ci(40,'D')));
    Q.push(make_pair(5,ci(50,'E')));
    
    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second.first;
        z=Q.front().second.second;
        cout<<x<<' '<<y<<' '<<z<<'\n';
        Q.pop();
    }
    return 0;
}
