//
//  main.cpp
//  9663 N-Queen
//
//  Created by 김유진 on 10/07/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <stdio.h>
int horizontalCheck[20]={0,};
int verticalCheck[20]={0,};
int rightCheck[40]={0,}; //-
int leftCheck[40]={0,};//+
int dap=0;
int n;

int dapArrX[20]={0,};
int dapArrY[20]={0,};
void func(int x, int y, int num)
{
    if(num==n)
    {
//        for(int i=0 ; i<n; i ++)
//        {
//            printf("%d %d\n",dapArrX[i],dapArrY[i]);
//        }
//        printf("\n");
        dap++;
        return;
    }
   
    int i=x+1;
    for(int j=0 ; j<n ; j++)
    {
        if(horizontalCheck[i]==0 &&
           verticalCheck[j]==0 &&
           rightCheck[i-j+15]==0 &&
           leftCheck[i+j]==0)
        {
            horizontalCheck[i]=1;
            verticalCheck[j]=1;
            rightCheck[i-j+15]=1;
            leftCheck[i+j]=1;
            
            dapArrX[num]=i;
            dapArrY[num]=j;
            func(i,j,num+1);
            
            horizontalCheck[i]=0;
            verticalCheck[j]=0;
            rightCheck[i-j+15]=0;
            leftCheck[i+j]=0;
        }
    }
}

int main()
{
//    freopen("/Users/kim-yujin/Documents/알고리즘/9663 N-Queen/9663 N-Queen/input.txt","r",stdin);
    scanf("%d",&n);
    func(0,0,0);
    printf("%d\n",n);
    printf("%d",dap);
}
