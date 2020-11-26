//
//  main.cpp
//  2493 탑
//
//  Created by 김유진 on 2020/03/11.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>

using namespace std;

int main()
{
    int n;
    int data[510000]={0,};
    deque<int> stack;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    stack.push_back(0);
    printf("0 ");
    for(int i=1 ; i<n ; i++)
    {
        int back = stack.back();
        while(data[back] < data[i])
        {
//            printf("%d\n",data[back]);
            stack.pop_back();
            if(stack.size()>0)
            {
                back = stack.back();
            }
            else
            {
                break;
            }
        }
        if(stack.size()==0)
        {
            back=-1;
        }
        printf("%d ",back+1);
        stack.push_back(i);
    }
}
