//
//  main.cpp
//  14888 연산자 끼워넣기
//
//  Created by 김유진 on 02/10/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;

int N;
int data[1010]={0,};
int opt[5]={0,}; // operator
int min=2100000000,max=-2100000000;

void func(int i,int o,int v)
{
    
    int num=v;
    if(i!=0)
    {
        switch (o) {
            case 0:
                num=v+data[i];
                break;
            case 1:
                num=v-data[i];
                break;
            case 2:
                num=v*data[i];
                break;
            case 3:
                num=v/data[i];
                break;
        }
    }
    
    if(N-1==i)
    {
        if(max<num)
            max=num;
        if(min>num)
            min=num;
        return;
    }
    
    for(int k=0 ; k<4 ; k++)
    {
        if(opt[k]>0)
        {
            opt[k]--;
            func(i+1,k,num);
            opt[k]++;
        }
    }
    
}

int main()
{
    scanf("%d",&N);
    
    for(int i=0; i <N ; i++)
    {
        scanf("%d",&data[i]);
    }
    for(int i=0 ; i<4 ; i++)
    {
        scanf("%d",&opt[i]);
    }
    func(0,-1,data[0]);
    
    printf("%d\n",max);
    printf("%d\n",min);
}
