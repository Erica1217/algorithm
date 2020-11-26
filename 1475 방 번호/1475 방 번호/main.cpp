//
//  main.cpp
//  1475 방 번호
//
//  Created by 김유진 on 13/08/2019.
//

#include <stdio.h>
#include <string.h>
int main()
{
    int max=0;
    int data[15]={0,};
    char input[10];
    scanf("%s",input);
    int n=strlen(input);
    
    for(int i=0; i<n ; i++)
    {
        data[input[i]-'0']++;
    }
    
    for(int i=0 ; i<9 ; i++)
    {
        int a=data[i];
        if(i==6)
        {
            int b=data[i]+data[9];
            a=(b/2)+(b%2);
        }
        
        if(a>max)
        {
            max=a;
        }
    }
    printf("%d",max);
}
