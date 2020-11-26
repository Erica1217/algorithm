//
//  main.cpp
//  6086 최대유량
//
//  Created by 김유진 on 2020/08/10.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;

bool hasResult=false;

int get_index(char a)
{
    if('A'<=a && a<='Z')
    {
        return a-'A';
    }
    return a-'a'+26;
}

int check[110]={0,};
int n;
int data[100][100]={0,};
int m=2100000000;
int path[110]={0,};
int result=0;

void func(int num,int s)
{
    if(hasResult)
    {
        return;
    }
    if(s==25)
    {
        hasResult=true;
        for(int i=1 ; i<num ; i++)
        {
            int a = path[i-1];
            int b = path[i];
            data[a][b]-=m;
            data[b][a]+=m;
        }
        result+=m;
        return;
    }
    
    for(int i=0 ; i<=51 ; i++)
    {
        if(check[i]==0 && data[s][i]>0)
        {
            m = m < data[s][i] ? m : data[s][i];
            check[i]=1;
            path[num]=i;
            func(num+1,i);
            check[i]=0;
        }
    }
}

int main()
{
    char a,b;
    int c;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("\n%c %c %d",&a,&b,&c);
        int A,B;
        A = get_index(a);
        B = get_index(b);
        data[A][B]+=c;
        data[B][A]+=c;
    }
    
    check[0]=1;
    do{

        hasResult=false;
        m = 2100000000;
        path[0]=0;
        func(1,0);
        if(!hasResult)
        {
            break;
        }
    }while(true);
    
    printf("%d\n",result);
}
