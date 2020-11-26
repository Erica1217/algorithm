//
//  main.cpp
//  14889 스타트와 링크
//
//  Created by 김유진 on 2020/04/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int input[25][25]={0,};
int check[25]={0,};
int n;
int result=9999999;
int abs(int a)
{
    return a<0?-1*a:a;
}
void func(int num, int bef)
{
    if(num==n/2)
    {
        int a=0,b=0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(check[i]==0 && check[j]==0)
                {
                    a+=(input[i][j]+input[j][i]);
                    
                }
                else if(check[i]==1 && check[j]==1)
                {
                    b+=(input[i][j]+input[j][i]);
                }
            }
        }
        if(abs(a-b)<result)
        {
            result=abs(a-b);
        }
        return;
    }
    for(int i=bef+1 ; i<n ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            func(num+1,i);
            check[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    func(0,-1);
    printf("%d",result);
}
