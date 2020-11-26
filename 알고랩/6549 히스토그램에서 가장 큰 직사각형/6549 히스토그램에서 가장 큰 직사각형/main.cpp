//
//  main.cpp
//  6549 히스토그램에서 가장 큰 직사각형
//
//  Created by 김유진 on 2020/03/27.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;

int input[110000]={0,};
int left[110000]={0,};
int right[110000]={0,};
int data[110000]={0,};

int main()
{
    do{
        int n;
        scanf("%d",&n);
        if(n==0)
        {
            return 0;
        }
        
        int top=1;
        
        for(int i=1 ; i<=n ; i++)
        {
            scanf("%d",&input[i]);
        }
        
        data[0]=0;
        data[n+1]=0;
        input[n+1]=0;
        int i=1;
        while(i<=n+1)
        {
            while((input[data[top-1]]<input[i] || input[data[top-1]]==input[i]) && i<=n+1)
            {
                left[i] = input[i] == input[data[top-1]] ? left[data[top-1]]:data[top-1];
                data[top++]=i;
                i++;
            }

            
            while(input[data[top-1]]>input[i] || (top!=1 && i>=n+1))
            {
                if(top==1)
                {
                    break;
                }
                right[data[top-1]] = i;
                top--;
            }
        }

        
        long long result=0;
        for(int j=1 ; j<=n ; j++)
        {
            long long t=(long long)(right[j]-left[j]-1)*(long long)input[j];
            result = result<t ?t:result;
        }
        printf("%lld\n",result);
    }while(true);
}
