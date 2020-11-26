//
//  main.cpp
//  12101 1,2,3 더하기 2
//
//  Created by 김유진 on 2020/07/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int n,k;
int r=0;
bool hasResult=false;
int data[100]={0,};

void func(int num, int sum)
{
    if(sum==n)
    {
        r++;
        if(r==k)
        {
            for(int i=0 ; i<num-1 ; i++)
            {
                printf("%d+",data[i]);
            }
            printf("%d",data[num-1]);
            hasResult=true;
        }
        return;
    }
    else if(sum>n || hasResult)
    {
        return;
    }
    
//    int start = num==0 ?1:data[num-1];
    for(int i=1; i<=3 ; i++)
    {
        data[num]=i;
        func(num+1,sum+i);
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    func(0,0);
    if(!hasResult)
    {
        printf("-1");
    }
}
