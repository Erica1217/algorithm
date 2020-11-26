//
//  main.cpp
//  16199 나이 계산하기
//
//  Created by 김유진 on 13/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
int main()
{
    int year1,mon1,day1;
    int year2,mon2,day2;
    scanf("%d %d %d",&year1,&mon1,&day1);
    scanf("%d %d %d",&year2,&mon2,&day2);
    
    int dap1,dap2,dap3;
    int check=0;
    if(mon2>mon1 || (mon1==mon2 && day2>=day1))
    {
        check=1;
    }
    dap1 = year2-year1-1+check;
    dap2 = year2-year1+1;
    dap3 = dap2-1;
    
    printf("%d\n",dap1);
    printf("%d\n",dap2);
    printf("%d\n",dap3);
}
