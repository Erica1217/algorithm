//
//  main.cpp
//  14891 톱니바퀴
//
//  Created by 김유진 on 2020/04/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int dv(int a){
    return a%8;
}

int main()
{
    int gear[5][10]={0,};
    int top[5]={0,};
    int k=0;
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<8 ; j++)
        {
            scanf("%1d",&gear[i][j]);
        }
    }
    
    for(int i=0 ; i<4 ; i++)
    {
        top[i]=800;
    }
    scanf("%d",&k);
    while(k--)
    {
        int n,clockwise=0;
        scanf("%d %d",&n,&clockwise);
        n--;

        bool left=true;
        int c = clockwise;
        int num=n;
        int leftN=0;
        while(left)
        {
            left=false;
//            printf("left : %d %d\n",gear[dv(top[num]-2)] , gear[dv(top[num-1]+2)]);
            if(num-1>=0 && gear[num][dv(top[num]-2)]!=gear[num-1][dv(top[num-1]+2)])
            {
                left=true;
                leftN++;
            }
            c*=-1;
            num--;
        }
        bool right=true;
        c=clockwise;
        num=n;
        int rightN=0;
        while(right)
        {
            right=false;
            if(num+1<4 && gear[num][dv(top[num]+2)]!=gear[num+1][dv(top[num+1]-2)])
            {
                right=true;
                rightN++;
            }
            c*=-1;
            num++;
        }
        c=clockwise;
        for(int i=1 ; i<=leftN ; i++)
        {
            top[n-i]+=c;
            c*=-1;
        }
        top[n]+=(clockwise*-1);
        c=clockwise;
        for(int i=1 ; i<=rightN ; i++)
        {
            top[n+i]+=c;
            c*=-1;
        }
//        printf("[%d] ",n);
//        for(int i=0 ; i<4 ; i++)
//        {
//            printf("%d ",top[i]);
//        }
//        printf("\n");
    }
    
    int result=0;
    int a=1;
    for(int i=0 ; i<4 ; i++)
    {
        result+=gear[i][dv(top[i])]*a;
        a*=2;
    }
    printf("%d\n",result);
}
