//
//  main.cpp
//  1991 트리 순회
//
//  Created by 김유진 on 2020/08/27.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
int data[1010][3]={0,};

void preorder(int t)
{
    printf("%c",t+'A');
    if(data[t][0]!=-1)
    {
        preorder(data[t][0]);
    }
    if(data[t][1]!=-1)
    {
        preorder(data[t][1]);
    }
    return;
}

void inorder(int t)
{
    if(data[t][0]!=-1)
    {
        inorder(data[t][0]);
    }
    printf("%c",t+'A');
    if(data[t][1]!=-1)
    {
        inorder(data[t][1]);
    }
    return;
}

void postorder(int t)
{
    if(data[t][0]!=-1)
    {
        postorder(data[t][0]);
    }
    if(data[t][1]!=-1)
    {
        postorder(data[t][1]);
    }
    printf("%c",t+'A');
    return;
}

int getIndex(char a)
{
    if(a=='.')
        return -1;
    return a-'A';
}

int main()
{
    scanf("%d",&n);
    
    
    char a,b,c;
    for(int i=0; i<n ; i++)
    {
        scanf("\n%c %c %c",&a,&b,&c);
        data[a-'A'][0]=getIndex(b);
        data[a-'A'][1]=getIndex(c);
    }
    
//    for(int i=0 ; i<='G'-'A' ; i++)
//    {
//        printf("%d %d %d\n",i,data[i][0],data[i][1]);
//    }
    
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
}
