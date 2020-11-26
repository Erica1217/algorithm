//
//  main.cpp
//  14500 테크로미노
//
//  Created by 김유진 on 2020/08/18.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n,m;
int input[550][550]={0,};
int check[550][550]={0,};
    

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0; j<m ; j++)
        {
            scanf("%d",input[i][j]);
        }
    }
}
