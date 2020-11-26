//
//  main.cpp
//  9251 LCS
//
//  Created by 김유진 on 2020/01/29.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>

int main()
{
    char s1[1010], s2[1010];
    int n1, n2;
    int data[1010][1010]={0,};
    scanf("%s\n",s1);
    scanf("%s",s2);
    n1 = strlen(s1);
    n2 = strlen(s2);
    
//    printf("%d %d\n",n1,n2);
    for(int i=1 ; i<=n1 ; i++)
    {
        for(int j=1 ; j<=n2 ; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                data[i][j] = data[i-1][j-1]+1;
            }else
            {
                data[i][j] = data[i-1][j] < data[i][j-1] ? data[i][j-1] : data[i-1][j];
            }
        }
    }
    
    printf("%d",data[n1][n2]);
}
