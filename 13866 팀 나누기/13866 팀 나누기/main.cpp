//
//  main.cpp
//  13866 팀 나누기
//
//  Created by 김유진 on 2020/08/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int data[10];
    for(int i=0 ; i<4 ; i++)
    {
        scanf("%d",&data[i]);
    }
    sort(data,data+4);
    
    int result =(data[0]+data[3]) - (data[1]+data[2]);
    result = result<0 ? result*-1 :result;
    printf("%d",result);
}
