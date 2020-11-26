//
//  main.cpp
//  1201 NMK
//
//  Created by 김유진 on 30/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>

int n,m,k;
int result[600]={0,};
bool isPossible=false;

void find(int n, int m, int k)
{
    int remainder = n%m;
    int minLength=(n/m) + (remainder==0 ? 0 : 1);
    if(minLength>k)
    {
        return ;
    }
    isPossible=true;
    for(int i=1 ; i<=m ; i++)
    {
        result[i] = n/m;
        if(remainder > 0)
        {
            result[i]++;
            remainder--;
        }
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    result[0]=k;
    
    if(!(m+k-1<=n && n<=m*k))
    {
        printf("-1");
        return 0;
    }
    
    if(m==1)
    {
        for(int i=n ; i>=1 ; i--)
        {
            printf("%d ",i);
        }
        return 0;
    }
    
    find(n-k,m-1,k);
    
    int before=0;
               
    for(int i=0 ; i<m ; i++)
    {
        for(int j=before+result[i]; j>before ; j--)
        {
            printf("%d ",j);
        }
        before+=result[i];
    }
}
