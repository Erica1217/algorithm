//
//  main.cpp
//  10971 외판원 순회2
//
//  Created by 김유진 on 2020/11/14.
//

#include <cstdio>
int w[15][15]={0,};
int n;
int check[15]={0,};
int result=-1;
int start=0;
void func(int num, int before, int v)
{
    if(num==n)
    {
        v+= w[before][start];
        if((v<result || result==-1) && w[before][start]!=0)
        {
            result=v;
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        if(check[i]==0 && w[before][i] != 0)
        {
            check[i]=1;
            func(num+1, i, v+w[before][i]);
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    
    for(int i=0 ; i<n ; i++)
    {
        start=i;
        check[i]=1;
        func(1,start,0);
        check[i]=0;
    }
    printf("%d",result);
}
