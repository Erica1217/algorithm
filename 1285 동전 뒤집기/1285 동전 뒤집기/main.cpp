//
//  main.cpp
//  1285 동전 뒤집기
//
//  Created by 김유진 on 2020/03/05.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>

using namespace std;
int n;
int data[25][25];
int rcheck[25]={0,};
int ccheck[25]={0,};
int csum[25]={0,};
int rsum[25]={0,};

void output()
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            printf("%d",data[i][j]);
        }
        printf("[%d]\n",rsum[i]);
    }
    printf("----\n");
    for(int i=0 ; i<n ; i++)
    {
        printf("%d",csum[i]);
    }
    printf("\n\n");
    
}
int main()
{
    char input[25][25];
    scanf("%d",&n);
    
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",input[i]);
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            data[i][j] = input[i][j]=='T'?1:0;
            rsum[i]+=data[i][j];
            csum[j]+=data[i][j];
        }
    }
    
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        result+=csum[i];
    }
    
    int i=0;
    bool change=false;
    bool row=false;
    while(true)
    {
        if(i==n)
        {
            if(change)
            {
                i=0;
                change=false;
                row=!row;
            }
            else
            {
                break;
            }
        }
        
        if(!row && csum[i]>n/2 && ccheck[i]==0)
        {
            ccheck[i]=1;
            result = result-csum[i]+n-csum[i];
            csum[i] = n-csum[i];
            
            for(int j=0 ; j<n ; j++)
            {
                data[j][i]=1-data[j][i];
                rsum[j]+= data[j][i]==0? -1:1;
            }
            printf("*%d\n",result);
            change=true;
            output();
        }
        
        if(row && rsum[i]>n/2 && rcheck[i]==0)
        {
            rcheck[i]=1;
            result = result-rsum[i]+n-rsum[i];
            rsum[i] = n-rsum[i];
            
            for(int j=0 ; j<n ; j++)
            {
                data[i][j]=1-data[i][j];
                csum[j]+= data[i][j]==0? -1:1;
            }
            printf("!%d\n",result);
            change=true;
            output();
        }
        i++;
    }
    printf("%d",result);
}

