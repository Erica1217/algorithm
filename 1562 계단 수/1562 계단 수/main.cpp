//
//  main.cpp
//  1562 계단 수
//
//  Created by 김유진 on 2020/11/16.
//

#include <cstdio>
using namespace std;
int mod(int a)
{
    return a%1000000000;
}
int main()
{
    int n;
    scanf("%d",&n);
    
//    모든 자리 들어갔는지 체크(비트 마스크), 마지막 수, 자리수
    int d[1100][12][110]={0,};

    for(int i=1 ; i<=9 ; i++)
    {
        d[1<<i][i][1] = 1;
    }
    
    for(int i=2 ; i<=n ; i++)
    {
        for(int j=0 ; j<=9 ; j++)
        {
            for(int k=1 ; k<=1023 ; k++)
            {
                if(j>0)
                    d[k|(1<<j)][j][i] = mod(d[k][j-1][i-1] + d[k|(1<<j)][j][i]);
                
                if(j+1<n)
                    d[k|(1<<j)][j][i] = mod(d[k|(1<<j)][j][i] + d[k][j+1][i-1]);
            }
        }
    }
    int result=0;
    for(int i=0 ; i<=9 ; i++)
    {
        result=mod(d[1023][i][n]+result);
    }
    printf("%d",result);
}
