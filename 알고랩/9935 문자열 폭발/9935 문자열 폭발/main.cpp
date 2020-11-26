//
//  main.cpp
//  9935 문자열 폭발
//
//  Created by 김유진 on 2020/03/27.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    char input[1100000];
    char bombStr[1100];
    int bombCheck[150]={0,};
    int check[1100000]={0,};
    scanf("%s",input);
    scanf("%s",bombStr);
    
    int bombN = strlen(bombStr);
    int n = strlen(input);
    
    for(int i=0 ; i<bombN ; i++)
    {
        bombCheck[bombStr[i]] = i+1;
    }
    
    int top=0;
    vector<pair<int, int>> data(11000000);
    
    for(int i=0 ; i<n ; i++)
    {
        int ch = bombCheck[input[i]];
        if(ch!=0 && (top==0 || data[top-1].second+1>=ch))
        {
            data[top] = make_pair(i, ch);
            top++;
//            printf("%d %d\n",i,ch);
        }
        else
        {
            top=0;
        }
    
        if(ch==bombN && top>=bombN)
        {
//            printf("[%d] %d %d\n",ch,top,bombN);
            bool isSame = true;
//            printf("------\n");
            for(int j=0 ; j<bombN ; j++)
            {
//                printf("%d %d\n",data[top-1-j].second ,bombN-j);
                if(data[top-1-j].second != bombN-j)
                {
                    isSame = false;
                    break;
                }
            }
//            printf("------\n");
            if(isSame)
            {
//                printf("dele\n");
                for(int j=0 ; j<bombN ; j++)
                {
                    check[data[top-1].first] = 1;
                    top--;
                }
            }
        }
    }
    
    int cnt=0;
    for(int i=0 ; i<n ;i++)
    {
        if(check[i]==0)
        {
            printf("%c",input[i]);
            cnt++;
        }
    }
    if(cnt==0)
    {
        printf("FRULA");
    }
    
}
