//
//  main.cpp
//  1943 동전분배
//
//  Created by 김유진 on 2020/05/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

using namespace std;
int data[110][51000]={0,};

int main()
{
    int T=3;
    int n;
    while(T--)
    {
        scanf("%d",&n);
        int sum=0;
        int coin[110]={0,};
        int coinNum[110]={0,};
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d %d",&coin[i],&coinNum[i]);
            sum+=(coin[i]*coinNum[i]);
        }
        if(sum%2==1)
        {
            printf("0\n");
            continue;
        }
        
        int result[110000]={0,};
        
        result[0]=1;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=1 ; j<=coinNum[i] ; j++)
            {
                int c = coin[i]*j;
                for(int k=sum/2 ; k>=c ; k--)
                {
                    if(k-c>=0 && result[k-c]==1)
                        result[k]=1;
                }
            }
            if(result[sum/2]==1)
            {
                printf("1\n");
                break;
            }
        }
        if(result[sum/2]==0)
            printf("0\n");
    }
}
