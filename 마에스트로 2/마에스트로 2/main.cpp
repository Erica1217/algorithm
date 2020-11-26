//
//  main.cpp
//  마에스트로 2
//
//  Created by 김유진 on 2020/03/14.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    
    for(int a=0 ; a<T ; a++)
    {
        int input[60][60]={0,};
        int data[60][60]={0,};
        scanf("%d %d",&n,&m);
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                scanf("%d",&input[i][j]);
            }
        }
        
        int dx[5]={0,0,1,1};
        int dy[5]={0,1,0,1};
        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j=0 ; j<m-1 ; j++)
            {
                if(input[i][j]==1)
                {
                    bool isOne=true;
                    for(int k=0 ; k<4 ; k++)
                    {
                        int X= i+dx[k];
                        int Y= j+dy[k];
                        if(input[X][Y]!=1)
                        {
                            isOne=false;
                        }
                    }
                    if(isOne)
                    {
                        for(int k=0 ; k<4 ; k++)
                        {
                            int X= i+dx[k];
                            int Y= j+dy[k];
                            data[X][Y]=1;
                        }
                    }
                }
            }
        }
        
        bool isPossible=true;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(data[i][j]!= input[i][j])
                {
                    isPossible=false;
                }
            }
        }
        printf(isPossible?"YES\n":"NO\n");
    }
}
