//
//  main.cpp
//  근묵자흑
//
//  Created by 김유진 on 2020/03/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n,k;
    int data[110000]={0,};
    scanf("%d %d",&n,&k);
    int index1=0;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&data[i]);
        if(data[i]==1)
        {
            index1=i;
        }
    }
    
    int result=n;
    int leftN,rightN;
    for(int i=0 ; i<k ; i++)
    {
        int index = index1 - i;
        leftN=index;
        rightN =n-(index+k);
        if(index<0 || leftN<0 || rightN<0)
        {
            continue;
        }
        int r = leftN/(k-1) + (leftN%(k-1)==0?0:1);
//        printf("%d ",r);
        r += rightN/(k-1)+(rightN%(k-1)==0?0:1);
//        printf("%d \n",r);
        r++;
        if(result > r)
        {
            result= r;
        }
    }
    printf("%d",result);
}
