//
//  main.cpp
//  4384 공평하게 팀 나누기
//
//  Created by 김유진 on 2020/05/31.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int input[110]={0,};
int data[110][50000]={0,};

bool desc(int a, int b){ return a > b; }
int abs(int n){
    return n>0?n:-n;
}

int main()
{
    int n;
    
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }

    
    sort(input,input+n,desc);
    int MAX = 450*100;
    data[0][input[0]]=1;
    for(int i=1 ; i<n ; i++)
    {
        int w = input[i];
        data[i][w]=1;
        for(int j=w ; j<=MAX ; j++)
        {
            int beforeW = data[i-1][j];
            if(beforeW>=1)
            {
                data[i][j+w] = beforeW+1;
            }
            if(data[i][j]==0)
            {
                data[i][j] = beforeW;
            }
        }
    }
    
    int sum=0;
    for(int i=0 ; i<n ; i++)
    {
        sum+=input[i];
    }
    
    int min=MAX;
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<=MAX ; j++)
        {
            if(data[i][j]==n/2 && min> abs(sum-j-j))
            {
                min = abs(sum-j-j);
                result=j;
            }
//            if(data[i][j]!=0)
//            {
//                printf("%d ",j);
//            }
        }
//        printf("\n");
    }
    
    result = result<sum-result ? result: sum-result;
    printf("%d %d\n",result,sum-result);
}
