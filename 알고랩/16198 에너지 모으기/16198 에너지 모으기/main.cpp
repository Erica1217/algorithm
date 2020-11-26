//
//  main.cpp
//  16198 에너지 모으기
//
//  Created by 김유진 on 2020/04/04.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
vector<int> data;
int n;
int check[20]={0,};
int result=0;
void func(int num)
{
    if(result<num)
    {
        result = num;
    }
    for(int i=1 ; i<n-1 ; i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            int l=-1, r=-1;
            for(int j=i-1 ; j>=0 ; j--)
            {
                if(check[j]==0)
                {
                    l=data[j];
                    break;
                }
            }
            
            for(int j=i+1 ; j<n ; j++)
            {
                if(check[j]==0)
                {
                    r=data[j];
                    break;
                }
            }
            func(num+(l*r));
            check[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    int a;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&a);
        data.push_back(a);
    }
    func(0);
    printf("%d",result);
}
