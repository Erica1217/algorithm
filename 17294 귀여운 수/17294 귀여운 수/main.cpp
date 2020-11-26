//
//  main.cpp
//  17294 귀여운 수
//
//  Created by 김유진 on 26/07/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
#include <string>
int main()
{
    char input[30]={0,};
    scanf("%s",input);
    unsigned long n = strlen(input);
    if(n==1){
        printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
        return 0;
    }
    int diff = input[0]-input[1];
    for(int i=0 ; i<n-1 ; i++)
    {
        if(diff != input[i]-input[i+1]){
            printf("흥칫뿡!! <(￣ ﹌ ￣)>");
            return 0;
        }
    }
    printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
}
