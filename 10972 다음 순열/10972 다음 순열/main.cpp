//
//  main.cpp
//  10972 다음 순열
//
//  Created by 김유진 on 2020/01/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
int input[10010]={0,};
int check[10010]={0,};
int data[10010]={0,};

bool isCheck=false;
bool printDap=false;

void func(int num, int right)
{
    
    if(isCheck && num==n && !printDap)
    {
        printDap = true;
        for(int i=0 ; i<num ; i++)
        {
            printf("%d ",data[i]);
        }
        printf("\n");
        return;
    }
    
    if(num==n)
    {
        if(right == n)
        {
            isCheck=true;
        }
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            data[num] = i;
            if(input[num] == i)
            {
                func(num+1, right+1);
            }
            else{
                func(num+1, right);
            }
            
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    func(0,0);
    
    if(!printDap)
    {
        printf("-1");
    }
}
