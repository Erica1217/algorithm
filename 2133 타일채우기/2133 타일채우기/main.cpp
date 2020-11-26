//
//  main.cpp
//  2133 타일채우기
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int data[40]={0,};
    
    data[1]=0;
    data[2]=3;
    data[3]=0;
    data[4]=11;
    
    int result=0;
    if(n%2==1){
        printf("0");
        return 0;
    }
    
    for(int i=6 ; i<=n ; i+=2)
    {
        data[i] = data[i-2] * data[2] + 2;
        
        int sum=0;
        for(int j=2 ; j<=i-4 ; j+=2)
        {
            sum+=data[j];
        }
        data[i] += sum*2;
    }
    printf("%d",data[n]);
}
