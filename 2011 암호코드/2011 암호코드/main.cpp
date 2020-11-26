//
//  main.cpp
//  2011 암호코드
//
//  Created by 김유진 on 09/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>

int main()
{
    char input[5010];
    int data[5010][2]={0,};
    scanf("%s",input);
    int n = strlen(input);
   
    if(input[0]=='0')
    {
        printf("0");
        return 0;
    }
    
    data[0][0]=1;
    data[0][1]=0;
    
    for(int i=1 ; i<n; i++)
    {
        int num = (input[i-1]-'0')*10 + input[i]-'0';
        
        if(input[i]=='0' && num<=26)
        {
            data[i][0] = 0;
            data[i][1] = data[i-1][0];
        }
        else if(num<=26)
        {
            data[i][0]=(data[i-1][0] + data[i-1][1])%1000000;
            data[i][1]=data[i-1][0];
        }
        else if(input[i]!='0')
        {
            data[i][0]=(data[i-1][0] + data[i-1][1])%1000000;
            data[i][1]=0;
        }
    }
    
    int result = (data[n-1][0] + data[n-1][1])%1000000;
    printf("%d",result);
}
