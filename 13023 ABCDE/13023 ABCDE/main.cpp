//
//  main.cpp
//  13023 ABCDE
//
//  Created by 김유진 on 2020/04/15.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> data[2020];
int isPossible=0;
int check[2020]={0,};
void func(int num, int curr){
    if(num>=4 || isPossible==1)
    {
        isPossible=1;
        return;
    }
    
    for(int i=0 ; i<data[curr].size() ; i++)
    {
        int x = data[curr][i];
        if(check[x]==0)
        {
            check[x]=1;
            func(num+1,x);
            check[x]=0;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int a,b;
    for(int i=0 ;i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        data[a].push_back(b);
        data[b].push_back(a);
    }
    for(int i=0 ; i<n ; i++)
    {
        check[i]=1;
        func(0,i);
        check[i]=0;
    }
    printf("%d",isPossible);
}
