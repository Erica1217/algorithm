//
//  main.cpp
//  16987 계란으로 계란치기
//
//  Created by 김유진 on 2020/03/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int n;
int s[10]={0,};
int w[10]={0,};
int result;

void func(int num)
{
    printf("%d : ",num);
    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
    if(num==n-1)
    {
        int egg=0;
        for(int i=0 ;i<n ; i++)
        {
            if(s[i]<=0)
            {
                egg++;
            }
        }
        if(result<egg)
        {
            result=egg;
        }
        return;
    }
    
    if(s[num]<=0)
    {
        func(num+1);
        return;
    }
        
    for(int i=0 ; i<n ; i++)
    {
        if(s[i]>0 && i!=num)
        {
            s[i]-=w[num];
            s[num]-=w[i];
            func(num+1);
            s[i]+=w[num];
            s[num]+=w[i];
        }
    }
}
 
int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&s[i],&w[i]);
    }
    
    func(0);
    printf("%d",result);
}
