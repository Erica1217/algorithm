//
//  main.cpp
//  2482 색상환
//
//  Created by 김유진 on 2020/11/13.
//

#include <iostream>
using namespace std;
int d[1010][1010]={0,};

int mod(long long n)
{
    return n%1000000003;
}
int main()
{
    int n,k;
    cin>>n>>k;
    
    for(int i=0 ; i<n ; i++)
    {
        d[0][i]=1;
    }
    
    for(int i=1 ; i<=k ; i++)
    {
        d[i][i*2] = 1;
        for(int j=i*2+1 ; j<n-1 ; j++)
        {
            d[i][j] = mod(d[i-1][j-2] + d[i][j-1]);
        }
        d[i][n-1] = d[i][n-2];
    }
    
    int result=0;
    for(int i=0 ; i<n ;i++)
    {
        result = mod(d[k-1][i]+result);
    }
    printf("%d",result);
}
