//
//  main.cpp
//  2154 수 이어쓰기 3
//
//  Created by 김유진 on 2020/07/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
int data[600000][10]={0,};
int main()
{
    char input[20];
    
    scanf("%s",input);
    int n= strlen(input);
    if(n==1)
    {
        printf("%c",input[0]);
        return 0;
    }
    
    int pos=0;
    int num=0;
    for(int i=1 ; i<=100000 ; i++)
    {
        string s = to_string(i);
        for(int j=0 ; j<s.length() ; j++)
        {
            num++;
            for(int k=0 ; k<=n-1 ; k++)
            {
                if(k==0 && input[k] == s.at(j))
                {
                    data[num][k+1]=i;
                }
                if(data[num-1][k]!=0 && input[k]==s.at(j))
                {
                    data[num][k+1]=data[num-1][k];
                    if(k+1==n)
                    {
                        printf("%d\n",num-n+1);
                        return 0;
                    }
                }
            }
        }
    }
}
