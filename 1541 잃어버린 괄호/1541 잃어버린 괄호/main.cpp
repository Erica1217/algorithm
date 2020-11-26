//
//  main.cpp
//  1541 잃어버린 괄호
//
//  Created by 김유진 on 30/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    char data[60]={0,};
    scanf("%s",data);
    int n= strlen(data);
    
    int result=0;
    int number=0;
    bool hasMinus=false;
    for(int i=0 ;i<n ; i++)
    {
        if('0'<=data[i] && data[i]<='9')
        {
            number*=10;
            number+=data[i]-'0';
        }
        else
        {
            if(hasMinus)
                result+=(number*-1);
            else
                result+=number;
            hasMinus = data[i]=='-' ? true: hasMinus;
            number=0;
        }
    }
    if(hasMinus)
        result+=(number*-1);
    else
        result+=number;
    printf("%d",result);
}
