//
//  main.cpp
//  최소값찾기
//
//  Created by 김유진 on 2020/04/25.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n, q;
    int data[1000]={0,};
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&q);
    
    int depth;
    int start=1;
    for(int i=1 ; i<=n ; i*=2)
    {
        start=i;
    }
    start*=2;
    for(int i=start ; i<start+n ; i++)
    {
        scanf("%d",&data[i]);
        
        int idx=i/2;
        while(idx!=0 && (data[idx]==0 || data[idx]>data[i]))
        {
            data[idx]=data[i];
            idx/=2;
        }
    }
    
    int l,r; //ㅣ은 짝수 r은 홀수
    while(q--)
    {
        scanf("%d %d",&l,&r);
        l+=start-1;
        r+=start-1;
        int min=data[l];
        if(l%2==1)
        {
            if(min>data[l])
            {
                min=data[l];
            }
            l++;
        }
        if(r%2==0)
        {
            if(min>data[r])
            {
                min=data[r];
            }
            r--;
        }
        while(l<r)
        {
//            printf("%d %d\n",l,r);
            if(min>data[l])
            {
                min=data[l];
            }
            if(min>data[r])
            {
                min=data[r];
            }
            
            if(l%2==1)
            {
                if(min>data[l])
                {
                    min=data[l];
                }
                l++;
            }
            if(r%2==0)
            {
                if(min>data[r])
                {
                    min=data[r];
                }
                r--;
            }
            
            l/=2;
            r/=2;
        }
        if(l==r)
        {
            if(min>data[r])
                
             {
                 min=data[r];
             }
        }
        printf("%d\n",min);
    }
}

