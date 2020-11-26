//
//  main.cpp
//  5213 과외맨
//
//  Created by 김유진 on 2020/03/04.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;
int data[510][1010]={0,};
int check[510][1010]={0,};
int result[510000]={0,};

struct strt{
    int x;
    int y;
    int before;
    int tile;
    int num;
};

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i%2 ; j<(n*2)-(i%2) ; j+=2)
        {
            scanf("%d %d",&data[i][j], &data[i][j+1]);
        }
    }
    
    vector<strt> queue;
    strt s;
    s.x=0;
    s.y=0;
    s.num=0;
    s.tile=1;
    s.before=0;
    
    queue.push_back(s);
    
    int start=0;
    while(queue.size()> start)
    {
        strt t = queue[start];
        int x = t.x;
        int y = t.y;
        
//        printf("%d %d %d %d\n",y,x,start,t.num);
        if(y==n-1 && x==n*2-2)
        {
            printf("%d\n",t.num+1);
            int index = start;
            strt temp = t;
            int a=t.num;
            while(index!=0)
            {
//                printf("*%d %d %d\n",temp.y,temp.x,temp.tile);
                if(result[a+1] != temp.tile)
                {
                    result[a] = temp.tile;
                    a--;
                }
                temp = queue[index];
                index = temp.before;
            }
            result[0]=1;
            for(int i=0 ; i<=t.num ; i++)
            {
                printf("%d ",result[i]);
            }
            return 0;
        }
        
        if(x%2 == y%2 && x+1 < (n*2)-(x%2)
           &&( check[y][x+1]==0 || check[y][x+1]>t.num))
        {
            check[x+1][y]=t.num;
            strt a;
            a.x=x+1;
            a.y=y;
            a.num = t.num;
            a.before = start;
            a.tile = t.tile;
            queue.insert(queue.begin()+start+1,a);
//            queue.push_back(a);
        }
        else if(x+1 < (n*2)-(x%2) && data[y][x] == data[y][x+1]
                && (check[y][x+1]==0 || check[y][x+1]>t.num+1))
        {
            check[y][x+1]=t.num+1;
            strt a;
            a.x=x+1;
            a.y=y;
            a.num = t.num+1;
            a.before = start;
            a.tile = t.tile+1;
            queue.push_back(a);
        }
        
        if(x!=n*2-1 && y+1<n && data[y+1][x] == data[y][x]
           && (check[y+1][x]==0 || check[y+1][x]>t.num+1))
        {
            check[y+1][x]=t.num+1;
            strt a;
            a.x=x;
            a.y=y+1;
            a.num = t.num+1;
            a.before = start;
            a.tile  = t.tile + (n-1);
            if((x%2) + (y%2)==1)
            {
            a.tile++;
            }
            queue.push_back(a);
        }
        start++;
    }
    strt maxTile=queue[0];
    for(int i=0 ; i<queue.size() ; i++)
    {
        if(maxTile.tile < queue[i].tile)
        {
            maxTile = queue[i];
        }
    }
    
    printf("%d\n",maxTile.num+1);
    int index = maxTile.before;
    strt temp = maxTile;
    int a=maxTile.num-1;
    result[a+1]=maxTile.tile;
    while(index!=0)
    {
        if(result[a+1] != temp.tile)
        {
            result[a] = temp.tile;
            a--;
        }
        temp = queue[index];
        index = temp.before;
    }
    result[0]=1;
    for(int i=0 ; i<=maxTile.num ; i++)
    {
        printf("%d ",result[i]);
    }
    return 0;
}
