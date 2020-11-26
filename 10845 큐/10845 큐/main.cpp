//
//  main.cpp
//  10845 큐
//
//  Created by 김유진 on 13/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

//push X: 정수 X를 큐에 넣는 연산이다.
//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 큐에 들어있는 정수의 개수를 출력한다.
//empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
//front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int queue[10010]={0,};
    int start=0,end=0;
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        char str[10];
        scanf("%s",str);
        if(strcmp(str,"push")==0)
        {
            int a;
            scanf("%d",&a);
            queue[end++]=a;
        }
        else if(strcmp(str,"pop")==0)
        {
            if(start==end)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",queue[start++]);
            }
        }
        else if(strcmp(str,"size")==0)
        {
            printf("%d\n",end-start);
        }
        else if(strcmp(str,"empty")==0)
        {
            if(start==end)
            {
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
        else if(strcmp(str,"back")==0)
        {
            if(start==end)
            {
                printf("-1\n");
            }
            else{
                printf("%d\n",queue[end-1]);
            }
        }
        else if(strcmp(str,"front")==0)
        {
            if(start==end)
            {
                printf("-1\n");
            }
            else{
                printf("%d\n",queue[start]);
            }
        }
    }
}
