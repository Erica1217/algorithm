//
//  main.cpp
//  1427 소트인사인드
//
//  Created by 김유진 on 27/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main()
{
    int n;
    char data[20];
    scanf("%s",data);
    n= strlen(data);
    sort(data,data+n,greater<>());
    printf("%s",data);
}

