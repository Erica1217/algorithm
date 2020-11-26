//
//  main.cpp
//  2560 짚신벌레
//
//  Created by 김유진 on 2020/11/21.
//

#include <cstdio>
int d[1100000]={0,};

int mod(int a)
{
    return a%1000;
}

int main()
{
    int a,b,c,N;
    scanf("%d %d %d %d",&a,&b,&c,&N);
    
    d[0]=1;
    int sum=0;
    
    for(int i=a ; i<b-1 ; i++)
    {
        sum=mod(sum+d[i-a]);
        d[i]=sum;
    }
    
    sum=0;
    for(int i=0; i<b-a ; i++)
    {
        sum+=d[i];
    }
    d[b-1]=sum;
    for(int i=b ; i<=N ; i++)
    {
        sum=(mod(sum-d[i-b]+1000));
        sum= mod(d[i-a]+sum);
        d[i]=mod(sum);
    }
    
    int result=0;
    int live = (N-c+1)<0? 0:(N-c+1);
    for(int i=N ; i>=live ; i--)
    {
        result=mod(result+d[i]);
    }
    printf("%d\n",result);
}
