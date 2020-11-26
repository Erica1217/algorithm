//
//  main.cpp
//  11506 占쏙옙
//
//  Created by 김유진 on 2020/01/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string>

using namespace std;

int main()
{
    char str[1010];
    for(int i=0 ; i<3; i++)
    {
        scanf("%s",&str);
        for(int j=0 ; j<strlen(str); j++)
        {
            if(str[j] != '占' && str[j]!='쏙' && str[j]!='옙')
            {
                printf("%c",str[j]);
            }
        }
    }
}
