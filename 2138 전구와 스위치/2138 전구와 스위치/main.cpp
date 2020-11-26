//
//  main.cpp
//  2138 전구와 스위치
//
//  Created by 김유진 on 2020/02/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>

int n;
char a[100100];
char b[100100];
char t[100100];

int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    
    int result=-1;
    
    int num=0;
    for(int j=0 ; j<2 ; j++)
    {
        for(int i=0 ; i<n ; i++)
        {
            t[i]=a[i];
        }
        for(int i=0 ; i<n-1 ; i++)
        {
            if(t[i] != b[i])
            {
                if(i+1==n-1)
                {
                    t[i] = (t[i]=='0')? '1' : '0';
                    t[i+1] = (t[i+1]=='0') ? '1' : '0';
                    num++;
                }
                else
                {
                    t[i] = (t[i]=='0')? '1' : '0';
                    t[i+1] = (t[i+1]=='0') ? '1' : '0';
                    t[i+2] = (t[i+2]=='0') ? '1' : '0';
                    num++;
                }
            }
//            printf("%d %d %s\n",j,i,t);
        }
        
        bool isSame=true;
        for(int k=0 ; k<n ; k++)
        {
            if(t[k] != b[k])
            {
                isSame=false;
                break;
            }
        }
        
        if(isSame &&  (result > num || result==-1))
        {
            result = num;
        }
        
        a[0] = (a[0]=='0') ? '1' : '0';
        a[1] = (a[1]=='0') ? '1' : '0';
        num=1;
    }
    printf("%d",result);
}
