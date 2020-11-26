//
//  main.cpp
//  2647 검은점과 하얀점 연결
//
//  Created by 김유진 on 2020/11/22.
//

#include <cstdio>

int main()
{
    int n;
    int input[110]={0,};
    int d[200][200]={0,};
    int next[200][200]={0,};
    scanf("%d",&n);
    
    for(int i=0 ; i<n; i++)
    {
        scanf("%1d",&input[i]);
    }
    
    for(int i=0 ; i<n-1 ; i++)
    {
        next[0][i] = i+1;
        if(input[i] != input[i+1])
        {
            d[0][i] = 3;
        }
    }
    next[0][n-1]=-1;
    
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            if(input[next[i-1][j]] != input[j] && input[i]==0)
            {
                d[i][j] = (next[i-1][j]-j) + (i+1)*2;
                next[i][j] = next[i-1][next[i-1][j]];
            }
        }
    }
    
    
    
    
}
