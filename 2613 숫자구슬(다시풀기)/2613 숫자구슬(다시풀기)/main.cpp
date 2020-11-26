//
//  main.cpp
//  2613 숫자구슬(다시풀기)
//
//  Created by 김유진 on 2020/11/21.
//

#include <cstdio>
using namespace std;

int max(int a, int b)
{
    return a>b? a:b;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    int input[400]={0,};
    int d[400][400]={0,};
    int idx[400][400]={0,};
    
    int sum=0;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
        sum+=input[i];
        d[0][i] = sum;
        idx[0][i]=-1;
    }
    
    sum=input[0];
    for(int i=1 ; i<n ; i++)
    {
        sum+=input[i];
        d[1][i] = sum;
        int t=0;
        for(int j=0 ; j<i ; j++)
        {
            t+=input[j];
            int a = max(sum-t , t);
            if(a < d[1][i])
            {
                d[1][i]=a;
                idx[1][i]=j;
            }
        }
    }
    
    for(int i=2 ; i<m ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            int s=input[j];
            
            d[i][j]=1000000000;
            for(int k=j-1 ; k>=i-1 ; k--)
            {
                int a = max(d[i-1][k],s);
                if(a<d[i][j])
                {
                    d[i][j]=a;
                    idx[i][j]=k;
                }
                s+=input[k];
            }
        }
    }
    
    int t=n-1;
    int result[330]={0,};
    for(int i=m-1 ; i>=0 ; i--)
    {
        result[i] = t-idx[i][t];
        t=idx[i][t];
    }
    
//    for(int i=0 ; i<n ; i++)
//    {
//        for(int j=0 ; j<n ; j++)
//        {
//            printf("%d ",d[i][j]);
//        }
//        printf("\n");
//    }
    
    printf("%d\n",d[m-1][n-1]);
    for(int i=0 ; i<m ; i++)
    {
        printf("%d ",result[i]);
    }
}
