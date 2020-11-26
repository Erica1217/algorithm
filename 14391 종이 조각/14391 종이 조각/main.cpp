//
//  main.cpp
//  14391 종이 조각
//
//  Created by 김유진 on 2020/04/11.
//  Copyright © 2020 김유진. All rights reserved.
//


#include <cstdio>
int n,m;
char input[10][10];
int check[10][10]={0,};
int result=0;
void func(int sum,int x, int y)
{
    if(sum>result)
    {
        result=sum;
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0; j<m ; j++)
        {
            if(check[i][j]==0)
            {
                int num1=0;
                int row=0;
                for(int k=0 ; k<(n-i) ; k++)
                {
                    if(check[i+k][j]==0)
                    {
                        num1*=10;
                        num1+=input[i+k][j]-'0';
                        check[i+k][j]=1;
                        row=k;
                        func(sum+num1,i,j);
                    }
                    else
                    {
                        break;
                    }
                }
                
                for(int k=0; k<=row;k++)
                {
                    check[i+k][j]=0;
                }

                int num2=0;
                int column=0;
                for(int k=0; k<(m-j) ; k++)
                {
                    if(check[i][j+k]==0)
                    {
                        num2*=10;
                        column=k;
                        num2+=input[i][j+k]-'0';
                        check[i][j+k]=1;
                        func(sum+num2,i,j);
                    }
                    else
                    {
                        break;
                    }
                }
                for(int k=0 ; k<=column ; k++)
                {
                    check[i][j+k]=0;
                }
                return;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    func(0,0,0);
    printf("%d",result);
}
