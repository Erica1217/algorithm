//
//  main.cpp
//  1717 집합의 표현 2
//
//  Created by 김유진 on 2020/08/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n,m;
int data[3300000]={0,};
int index(int a)
{
    if(a== data[a])
    {
        return a;
    }
    data[a] = index(data[a]);
    return data[a];
}

void merge(int a, int b)
{
    int A = index(a);
    int B = index(b);
    
    if(A!=B)
    {
        data[A] = B;
    }
}


int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        data[i]=i;
    }
    int a,b,c;
    for(int i=0; i<m ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0)
        {
            merge(b,c);
        }
        else
        {
            if(index(b)== index(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}
