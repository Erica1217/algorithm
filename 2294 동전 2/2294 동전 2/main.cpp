//
//  main.cpp
//  2294 동전 2
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    int num=0;
    int check[100100]={0,};
    int input[200]={0,};
    int data[10100]={0,};

    
    scanf("%d %d",&n,&k);
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        if(check[a]==0)
        {
            check[a]=1;
            input[num++]=a;
        }
    }
    data[0]=1;
    
    for(int i=0 ; i<num ; i++)
    {
        data[input[i]]=1;
        for(int j=input[i]; j<=k ; j++)
        {
            if((data[j] > data[j-input[i]]+1 || data[j]==0) && data[j-input[i]]!=0)
                data[j] = data[j-input[i]]+1;
        }
    }
    
//    for(int i=0 ; i<=k ; i++)
//    {
//        printf("%d\n",data[i]);
//    }
    
    if(data[k]==0)
    {
        printf("-1");
    }
    else
    {
        printf("%d", data[k]);
    }
}
