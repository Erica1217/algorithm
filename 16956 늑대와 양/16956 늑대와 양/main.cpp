//
//  main.cpp
//  16956 늑대와 양
//
//  Created by 김유진 on 2020/11/13.
//

#include <cstdio>

int n,m;
char data[550][550];

int dx[6] = {-1,1,0,0};
int dy[6] = {0,0,-1,1};

bool check(int x,int y)
{
    for(int i=0 ; i<4 ; i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;
        if(X>=0 && X<n && Y>=0 && Y<m)
        {
            if(data[X][Y] == 'W')
            {
                return false;
            }
            
            if(data[X][Y] == '.')
            {
                data[X][Y]='D';
            }
        }
    }
    return true;
}

int main()
{
    
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",data[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(data[i][j]=='S')
            {
                if(!check(i,j))
                {
                    printf("0\n");
                    return 0;
                }
                
            }
        }
    }
    printf("1\n");
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            printf("%c",data[i][j]);
        }
        printf("\n");
    }
    
}
