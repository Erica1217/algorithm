//
//  main.cpp
//  2485 가로수
//
//  Created by 김유진 on 2020/11/20.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}


int main()
{
    int n;
    scanf("%d",&n);
    
    int d[110000]={0,};
    
    int s,e;
    scanf("%d",&s);
    for(int i=0 ; i<n-1 ; i++)
    {
        scanf("%d", &e);
        d[i] = e-s;
        s=e;
    }
    
    sort(d,d+n-1);
    int v = d[0];
    for(int i=1; i<n-1 ; i++)
    {
        if(d[i]%v!=0)
        {
            v = gcd(v,d[i]);
        }
    }
    
    int result=0;
    for(int i=0 ; i<n-1 ; i++)
    {
        result += (d[i]/v)-1;
    }
//    printf("%d\n",v);
    printf("%d",result);
}
