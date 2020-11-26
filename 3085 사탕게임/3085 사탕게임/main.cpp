//
//  main.cpp
//  3085 사탕게임
//
//  Created by 김유진 on 2020/07/13.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;

int n;
char input[60][60];

int top_down(int x,int y)
{
    int result=1;
    int a=x+1,b=y;
    while(a<n)
    {
        if(input[a][b] == input[x][y])
        {
            result++;
            a++;
        }
        else
        {
            break;
        }
    }
    a=x-1;
    while(a>=0)
    {
       if(input[a][b] == input[x][y])
       {
           result++;
           a--;
       }
       else
       {
           break;
       }
    }
    return result;
}

int left_right(int x, int y)
{
    int result=1;
    int a=x,b=y+1;
    while(b<n)
    {
        if(input[a][b] == input[x][y])
        {
            result++;
            b++;
        }
        else
        {
            break;
        }
    }
    b=y-1;
    while(b>=0)
    {
       if(input[a][b] == input[x][y])
       {
           result++;
           b--;
       }
       else
       {
           break;
       }
    }
    return result;
}

int main()
{
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    int result=1;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            
        }
    }
    printf("%d",result);
}
