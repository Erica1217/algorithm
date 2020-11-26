//
//  main.cpp
//  1515 수 이어쓰기
//
//  Created by 김유진 on 2020/07/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    char data[3310];
    scanf("%s",data);
    int n= strlen(data);
    
    int cur=0;
    for(int i=1 ; ; i++)
    {
        string s=to_string(i);
        for(int j=0 ; j<s.length(); j++)
        {
            if(cur<n && data[cur] == s.at(j))
            {
                cur++;
            }
        }
        
        if(cur==n)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    
}
