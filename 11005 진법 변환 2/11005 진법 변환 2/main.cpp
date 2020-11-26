//
//  main.cpp
//  11005 진법 변환 2
//
//  Created by 김유진 on 2020/07/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
void change(int n,int b)
{
    if(n==0)
        return;
    
    change(n/b,b);
    int r=n%b;
    if(r>=10)
    {
        r-=10;
        printf("%c",'A'+r);
    }
    else
    {
        printf("%d",r);
    }
}
int main()
{
    int n,b;
    scanf("%d %d",&n,&b);
    change(n,b);
}
