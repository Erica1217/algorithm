//
//  main.cpp
//  2098 외판원 순회
//
//  Created by 김유진 on 2020/11/14.
//

#include <cstdio>
using namespace std;

/* 비트마스크 도시체크, 마지막 간 도시*/
int d[150000][20]={0,};
int start[150000][20]={0,};
int main()
{
    int n;
    int w[20][20]={0,};
    
    /* 입력 */
    scanf("%d",&n);
    for(int i=0 ; i<n; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&w[i][j]);
            d[(1<<i)|(1<<j)][j] = w[i][j];
            start[(1<<i)|(1<<j)][j] = i;
        }
    }
    
    for(int i=1 ; i<(1<<n) ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            for(int k=0 ; k<n ; k++)
            {
                if(w[j][k]!=0 && d[i][j]!=0 && !(i&(1<<k))
                   && (d[i|(1<<k)][k]==0 ||
                       d[i|(1<<k)][k] > d[i][j] + w[j][k]))
                {
                    d[i|(1<<k)][k] = d[i][j] + w[j][k];
                    start[i|(1<<k)][k] = start[i][j];
                }
            }
        }
    }
    
    int result= 200000000;
    for(int i=0 ; i<n ; i++)
    {
        int t=d[(1<<n)-1][i];
        int s = start[(1<<n)-1][i];
        if(result> t+w[i][s] && w[i][s]!=0 && t!=0)
        {
            result = t+w[i][s];
        }
    }
    printf("%d",result);
}


