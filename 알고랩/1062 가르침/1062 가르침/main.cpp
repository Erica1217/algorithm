//
//  main.cpp
//  1062 가르침
//
//  Created by 김유진 on 2020/04/22.
//  Copyright © 2020 김유진. All rights reserved.
//


#include <cstdio>
#include <string.h>
int n,k;
unsigned int data[60]={0,};
int result=0;
int check[30]={0,};

void func(int num,int before, unsigned int ret)
{

    if(num==k)
    {
        int r=0;
        for(int i=0; i<n; i++)
        {
            if((data[i]&ret)==data[i])
            {
                r++;
            }
        }
        if(r>result)
        {
            result=r;
        }
        return;
    }
    
    for(int i=before+1 ; i<=26 ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            func(num+1,i,(ret|(1<<i)));
            check[i]=0;
        }
    }
}

int main()
{
    char input[60][50]={0,};
    char d[10]={'a','c','t','n','i'};
    scanf("%d %d",&n,&k);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        int num = strlen(input[i]);
        for(int j=4 ; j<num-4 ; j++)
        {
            data[i]=data[i]|(1<<(input[i][j]-'a'));
        }
    }
    unsigned int r=0;
    for(int i=0 ; i<5 ; i++)
    {
        r+=(1<<(d[i]-'a'));
        check[d[i]-'a']=1;
    }
    func(5,-1,r);
    printf("%d\n",result);
}
