//
//  main.cpp
//  2250 트리의 높이와 너비
//
//  Created by 김유진 on 2020/08/27.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int data[11000][3]={0,};
int child[11000]={0,};
int index[11000]={0,};
int result[11000][3]={0,};
int check[11000]={0,};

int getChild(int node)
{
    if(node==-1)
    {
        return 0;
    }
    int leftNode = data[node][0];
    int rightNode = data[node][1];
    int left=0;
    int right=0;
    
    if(leftNode!=-1)
    {
        left = getChild(leftNode);
    }
    if(rightNode!=-1)
    {
        right = getChild(rightNode);
    }
    
    child[node]=left+right+1;
    return left+right+1;
}

void getIndex(int node, int l, int r,int depth)
{
    int leftNode = data[node][0];
    int rightNode = data[node][1];
    
    if(l==r)
    {
        index[node]=l;
    }
    if(leftNode!=-1)
    {
        index[node] = l+child[leftNode];
        getIndex(leftNode,l,index[node]-1,depth+1);
    }
    if(rightNode!=-1)
    {
        index[node] = r-child[rightNode];
        getIndex(rightNode,index[node]+1,r,depth+1);
    }
    
    if(result[depth][0]==0 || result[depth][0] > index[node])
    {
            result[depth][0]= index[node];
    }
    if(result[depth][1]==0 || result[depth][1]<index[node])
    {
        result[depth][1] = index[node];
    }
}


int main()
{
    int n;
    int root=-1;
    scanf("%d",&n);
    int a,b,c;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        data[a][0]=b;
        data[a][1]=c;
        check[b]=1;
        check[c]=1;
    }
    
    for(int i=1 ; i<=n ; i++)
    {
        if(check[i]==0)
        {
            root=i;
            break;
        }
    }
    
    getChild(root);
    getIndex(root, 1,n,1);
    
    int level=0, max=0;
    for(int i=1 ; i<=n; i++)
    {
        int s=result[i][1]-result[i][0]+1;
        if(max<s)
        {
            max=s;
            level=i;
        }
    }
    printf("%d %d\n",level,max);
}
