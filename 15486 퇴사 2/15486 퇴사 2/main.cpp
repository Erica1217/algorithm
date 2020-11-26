//
//  main.cpp
//  15486 퇴사 2
//
//  Created by 김유진 on 2020/02/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int n;
int t[1500010];
int p[1500010];
int data[1500010]={0,};
int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&t[i], &p[i]);
    }
    
    
    data[0]=0;
    data[t[0]] = p[0];
    for(int i=1 ; i<=n ; i++)
    {
        if(data[i] < data[i-1])
        {
            data[i] = data[i-1];
        }

        if(i+t[i] <=n && data[i+t[i]] < data[i]+p[i])
        {
            data[i+t[i]] = data[i]+p[i];
        }
    }
    printf("%d",data[n]);
}
