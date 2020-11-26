//
//  main.cpp
//  1406 에디터
//
//  Created by 김유진 on 2020/08/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
int main()
{
    char input[710000];
    int m;
    scanf("%s",input);
    scanf("%d",&m);
    
    char left[710000];
    char right[710000];
    
    strcpy(left, input);
    
    int lt=strlen(input);
    int rt=0;
    char cmd;
    for(int i=0 ; i<m ; i++)
    {
        scanf("\n%c",&cmd);
        if(cmd=='D')
        {
            if(rt!=0)
                left[lt++]=right[--rt];
        }
        else if(cmd=='L')
        {
            if(lt!=0)
                right[rt++]=left[--lt];
        }
        else if(cmd=='B')
        {
            if(lt!=0)
                lt--;
        }
        else if(cmd=='P')
        {
            char c;
            scanf(" %c",&c);
            left[lt++]=c;
        }
    }
    for(int i=0 ; i<lt ; i++)
    {
        printf("%c",left[i]);
    }
    for(int i=rt-1 ; i>=0 ; i--)
    {
        printf("%c",right[i]);
    }
}
