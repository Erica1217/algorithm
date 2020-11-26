//
//  main.cpp
//  야바위
//
//  Created by 김유진 on 2020/03/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int n, m, c;
    int input[110][2];
    scanf("%d %d %d",&n,&m,&c);
    
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&input[i][0], &input[i][1]);
    }
    
    for(int i=0 ; i<m ; i++)
    {
        if(input[i][0] == c)
        {
            c=input[i][1];
        }
        else if(input[i][1] == c)
        {
            c=input[i][0];
        }
    }
    printf("%d",c);
}
