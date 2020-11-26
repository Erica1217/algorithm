//
//  main.cpp
//  1248 맞춰봐
//
//  Created by 김유진 on 2020/04/11.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
char str[60]={0,};
char input[60][60]={0,};
int data[60]={0,};
int sum[60][60]={0,};
bool hasResult=false;

void func(int num)
{
    if(hasResult)
    {
        return;
    }
    if(num==n)
    {
        hasResult=true;
        for(int i=0 ; i<n ; i++)
        {
            printf("%d ",data[i]);
        }
        return;
    }
    
    int min,max;
    if(input[num][num]=='+')
    {
        min=1;
        max=10;
    }
    else if(input[num][num]=='-')
    {
        min=-10;
        max=-1;
    }
    else
    {
        min=0;
        max=0;
    }
    
    if(num>0)
    {
        for(int i=0 ; i<num ; i++)
        {
            int t1;
            int t2;
            switch (input[i][num]) {
                case '+':
                    t1 = 1-sum[i][num-1];
                    t2 = 10-sum[i][num-1];
                    break;
                case '-':
                    t1=-10-sum[i][num-1];
                    t2=-1-sum[i][num-1];
                    break;
                case '0':
                    t1=0-sum[i][num-1];
                    t2=0-sum[i][num-1];
                    break;
            }
            if(max<t1)
            {
                return;
            }
            if(min<t1)
            {
                min=t1;
            }
            if(t2<max)
            {
                max=t2;
            }
        }
    }
    
    for(int i=min ; i<=max ; i++)
    {
        for(int j=0; j<=num ; j++)
        {
            sum[j][num] = sum[j][num-1]+i;
        }
        data[num]=i;
        func(num+1);
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    
    int num=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            input[i][j]=str[num++];
        }
    }
    func(0);
}
