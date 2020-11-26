//
//  main.cpp
//  마에스트로 3
//
//  Created by 김유진 on 2020/03/14.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;
int input[3030]={0,};
int data[3030]={0,};

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input[i]);
    }
    
    for(int i=1 ; i<n ; i++)
    {
        data[i-1] = input[i]-input[i-1];
    }
    sort(data,data+n-1);
    int sum=0;
    for(int i=0 ; i<n-k ; i++)
    {
        sum+=data[i];
    }
    printf("%d",sum);
}
