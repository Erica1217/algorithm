//
//  main.cpp
//  11723 집합(비트연산)
//
//  Created by 김유진 on 2020/11/16.
//

#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    string s;
    int x;
    int d=0;
    while(m--)
    {
        cin>>s;
        if(s=="add")
        {
            cin>>x;
            d=d|(1<<x);
        }
        else if(s=="remove")
        {
            cin>>x;
            d = d & ~(1<<x);
        }
        else if(s=="check")
        {
            cin>>x;
            if(d & (1<<x))
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(s=="toggle")
        {
            cin>>x;
            d = d ^ (1<<x);
        }
        else if(s=="all")
        {
            d = (1<<21) -1;
        }
        else if(s=="empty")
        {
            d = 0;
        }
    }
}
