//
//  main.cpp
//  2116 주사위 쌓기
//
//  Created by 김유진 on 2020/11/20.
//

#include <cstdio>
using namespace std;
int n;
int d[11000][10]={0,};
int result=0;
int opp[10]={5,3,4,1,2,0};

void func(int num, int top, int sum)
{
//    printf("%d %d %d\n",num,top,sum);
    if(num==n)
    {
//        printf("%d %d\n",sum,top);
        result = result<sum ? sum : result;
        return;
    }

    int bottom=0;
    for(int i=0 ; i<6 ; i++)
    {
        if(d[num][i]==top)
        {
            bottom = i;
            break;
        }
    }
    
    for(int i=6 ; i>=1 ; i--)
    {
        if(d[num][bottom]!=i && d[num][opp[bottom]]!=i)
        {
//            printf("%d %d [%d]\n",d[num][bottom], d[num][opp[bottom]],i);
            func(num+1, d[num][opp[bottom]], sum+i);
            break;
        }
    }
}

int main()
{
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<6 ; j++)
        {
            scanf("%d",&d[i][j]);
        }
    }
    for(int i=0; i<6 ; i++)
    {
        for(int j=6 ; j>=1 ; j--)
        {
            if(d[0][i]!=j && d[0][opp[i]]!=j)
            {
                func(1,d[0][opp[i]],j);
                break;
            }
        }
    }
    printf("%d",result);
}
