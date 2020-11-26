//
//  main.cpp
//  3015 오아시스 재결합
//
//  Created by 김유진 on 2020/04/03.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n;
    int data[510000]={0,};
    int stack[510000]={0,};
    int same[510000]={0,};
    int top=0;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
    }
    int result=0;
    for(int i=0; i<n ;)
    {
        while((top==0 || stack[top-1]>=data[i])&& i<n){
            same[top] = (data[i]==stack[top-1])? same[top-1]+1 : 0;
            result+=((top==0)?0: (same[top]==0 || same[top]!= top-1)?same[top]+1:same[top]);
            printf("+%d %d [%d]: %d\n",stack[top-1],data[i],top,result);
            stack[top++]=data[i];
            i++;
        }
        
        while(top!=0 && stack[top-1]<data[i]){
            printf("-%d %d [%d]: %d\n",stack[top-1],data[i],top,result+1);
            result++;
            top--;
        }
    }
    printf("%d",result);
}
