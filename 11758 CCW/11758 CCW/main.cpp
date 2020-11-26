//
//  main.cpp
//  11758 CCW
//
//  Created by 김유진 on 2020/08/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int ax,ay;
    int bx,by;
    int cx,cy;
    scanf("%d %d",&ax,&ay);
    scanf("%d %d",&bx,&by);
    scanf("%d %d",&cx,&cy);
    
    
    int result = (ax*by + bx*cy + cx*ay) - (ay*bx + by*cx + cy*ax);
    result = result<0? -1 : result==0?0:1;
    printf("%d",result);
}
