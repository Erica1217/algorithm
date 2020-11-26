//
//  main.cpp
//  2666 벽장문의 이동
//
//  Created by 김유진 on 2020/11/16.
//

#include <cstdio>
#include <utility>
using namespace std;
pair<int ,int> open[1100000][25];
int d[1100000][25]={0,};
int door[25]={0,};
int n,m;

int abs(int a){
    return a>0 ? a: -a;
}

int result=-1;

void func(int num, int a, int b, int mv)
{
    if(num == m)
    {
        if(result==-1 || result>mv)
        {
            result= mv;
        }
        return;
    }
    
    if(a>b)
    {
        int t=a;
        a=b;
        b=t;
    }
    
    if(door[num]<a && door[num]<b)
    {
        func(num+1, door[num], b, mv + abs(door[num]-a));
    }
    else if(door[num]>a && door[num]>b)
    {
        func(num+1, door[num], a, mv + abs(door[num]-b));
    }
    else if(door[num]==a || door[num]==b)
    {
        func(num+1, a, b, mv);
    }
    else
    {
        func(num+1, door[num], b, mv + abs(door[num]-a));
        func(num+1, a, door[num], mv + abs(door[num]-b));
    }
    
}

int main()
{
    scanf("%d",&n);
    
    int a,b;
    scanf("%d %d",&a,&b);
    scanf("%d",&m);
    
    
    for(int i=0 ; i<m ; i++)
    {
        scanf("%d",&door[i]);
    }
    func(0,a,b,0);
    printf("%d",result);
}
