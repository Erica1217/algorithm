//
//  main.cpp
//  2884 알람시계
//
//  Created by 김유진 on 26/07/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int h,m;
    scanf("%d %d",&h,&m);
    
    m-=45;
    if(m<0){
        if(h==0){
            h=24;
        }
        h--;
        m+=60;
    }
    printf("%d %d",h,m);
}
