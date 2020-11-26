//
//  main.cpp
//  16283 Farm
//
//  Created by 김유진 on 17/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <cstdio>
int main()
{
    int a,b,n,w;
    scanf("%d %d %d %d",&a,&b,&n,&w);
    
    int sheep=-1,goat=-1;
    for(int i=1 ; i<n ; i++)
    {
        int j=n-i;
        if((i*a) + (j*b) == w)
        {
            if (!(sheep==-1 && goat==-1))
            {
                printf("-1");
                return 0;
            }
            sheep=i;
            goat=j;
        }
    }
    if(sheep==-1 && goat==-1)
    {
        printf("-1");
    }
    else{
        printf("%d %d",sheep,goat);
    }
}
