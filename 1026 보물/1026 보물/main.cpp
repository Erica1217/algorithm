//
//  main.cpp
//  1026 보물
//
//  Created by 김유진 on 02/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

bool desc(int a, int b){
    return a>b;
}

int main()
{
    int n;
    int a[110]={0,};
    int b[110]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&b[i]);
    }
    
    sort(a, a+n);
    sort(b, b+n, desc);
    
    int sum=0;
    for(int i=0 ; i<n ; i++)
    {
        sum+= a[i]*b[i];
    }
    printf("%d",sum);
    return 0;
}
