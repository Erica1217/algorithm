//
//  main.cpp
//  1182 부분수열의 합
//
//  Created by 김유진 on 2020/11/16.
//

#include <cstdio>
using namespace std;
int d[1100000]={0,};
int main()
{
    int N,S;
    int input[26]={0,};
    scanf("%d %d",&N,&S);
    for(int i=0 ; i<N ; i++)
    {
        scanf("%d",&input[i]);
        d[1<<i] = input[i];
    }
    int result=0;
    
    for(int i=1 ; i<=(1<<N)-1 ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            if(d[i|(1<<j)]==0 && 1<<j != i && d[i]!=0  )
            {
                d[i|(1<<j)] = d[i] + input[j];
            }
        }
        if(d[i] == S)
        {
            result++;
        }
    }
    
//    for(int i=1 ; i<=(1<<N)-1 ; i++)
//    {
//        printf("%d %d\n",i,d[i]);
//        if(d[i]==S)
//        {
////            result++;
//        }
//    }
    printf("%d\n",result);
}
