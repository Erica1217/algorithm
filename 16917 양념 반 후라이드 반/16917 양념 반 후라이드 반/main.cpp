//
//  main.cpp
//  16917 양념 반 후라이드 반
//
//  Created by 김유진 on 2020/03/22.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int main()
{
    int a,b,c,x,y;
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    
    int result=0;
    if(a+b > c*2)
    {
        int min = x<y?x:y;
        result += c*2*min;
        x-=min;
        y-=min;
    }
    
    if(x>0 && a>c*2)
    {
        result+= c*2*x;
        x=0;
    }
    
    if(y>0 && b>c*2)
    {
        result+= c*2*y;
        y=0;
    }
    
    if(x>0)
    {
        result+=a*x;
    }
    if(y>0)
    {
        result+=b*y;
    }
    
    printf("%d",result);
}
