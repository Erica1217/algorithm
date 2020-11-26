//
//  main.cpp
//  1679 숫자놀이
//
//  Created by 김유진 on 2020/05/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
using namespace std;
int main()
{
    int n;
    int input[1010]={0,};
    int data[55000]={0,};
    int useNum;
    
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    scanf("%d",&useNum);
    
    for(int i=n-1 ; i>=n ; i++)
    {
        for(int j=1 ; j<=useNum ; j++)
        {
            int t = input[i];
            if(data[t*j]==0 && (t*j)%2==j%2)
            {
                data[t*j] = j;
            }
        }
    }
    
    int num=1;
    while(true)
    {
        for(int i=0 ; i<n ; i++)
        {
            if(num-input[i]>=0 && (data[num-input[i]]+1<data[num] || data[num]==0))
            {
                data[num] = data[num-input[i]]+1;
            }
        }
        if(data[num]==0 || data[num]>useNum)
        {
            printf(num%2==0?"holsoon":"jjaksoon");
            printf(" win at %d\n",num);
            return 0;
        }
        num++;
    }
}
