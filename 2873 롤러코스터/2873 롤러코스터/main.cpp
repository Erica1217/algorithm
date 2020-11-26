//
//  main.cpp
//  2873 롤러코스터
//
//  Created by 김유진 on 2020/03/09.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>

int main()
{
    int r,c;
    int data[1010][1010]={0,};
    
    scanf("%d %d",&r,&c);
    
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ;j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    
    if(r%2 == 1)
    {
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<c-1 ; j++)
            {
                if(i%2==0)
                {
                    printf("R");
                }
                else
                {
                    printf("L");
                }
            }
            if(i!= r-1)
            {
                printf("D");
            }
        }
        return 0;
    }
    if(c%2 == 1)
    {
        for(int i=0 ; i<c ; i++)
        {
            for(int j=0 ; j<r-1 ; j++)
            {
                if(i%2==0)
                {
                    printf("D");
                }
                else
                {
                    printf("U");
                }
            }
            if(i!=c-1)
            {
                printf("R");
            }
        }
        return 0;
    }
    
    int x=1, y=0,m=data[1][0];
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            if((i%2) + (j%2) == 1 && m>data[i][j])
            {
                m=data[i][j];
                x=i;
                y=j;
            }
        }
    }
    
    bool isDown = true;
    int check=0;
    for(int i=0 ; i<r ; i++)
    {
        if(i==(x-(x%2)))
        {
            check=1;
            int a=i,b=0;
            while(!(i+1 == a && b==c-1))
            {
                if(isDown && !(a+1 == x && b==y))
                {
                    printf("D");
                    isDown=false;
                    a++;
                }
                else if(!isDown && !(a-1 == x && b==y))
                {
                    printf("U");
                    isDown=true;
                    a--;
                }
                if(b<c-1)
                {
                    printf("R");
                    b++;
                }
            }
            i++;
        }
        else
        {
            for(int j=0 ; j<c-1 ; j++)
            {
                if(i%2==check)
                {
                    printf("R");
                }
                else
                {
                    printf("L");
                }
            }
        }
        if(i!=r-1)
        {
            printf("D");
        }
    }
    return 0;
}
