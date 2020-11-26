//
//  main.cpp
//  2526 싸이클
//
//  Created by 김유진 on 2020/08/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    int data[1010]={0,};
    data[n]=1;
    int a=n;
    int cnt=1;
    int result=0;
    while(true)
    {
        int next=(a*n)%p;
        if(data[next]!=0)
        {
//            printf("%d %d\n",cnt,data[next]);
            result=cnt-data[next]+1;
            break;
        }
        data[next]=++cnt;
        a=next;
    }
    printf("%d",result);
}
