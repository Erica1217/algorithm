//
//  main.cpp
//  3653 영화 수집
//
//  Created by 김유진 on 2020/07/11.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
int tree[1000000]={0,};

void lazy_update()
{
    
}

int sum()
{
    
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        int input[110000]={0,};
//        int top[110000]={0,};
        int data[210000]={0,};
        scanf("%d %d",&n,&m);
        for(int i=0 ; i<m ; i++)
        {
            scanf("%d",&input[i]);
        }
        
        int pos[110000]={0,};
        int start = m+1;
        int end = start+n+1;
        for(int i=1 ; i<=n ; i++)
        {
            data[start+i-1]=i;
            pos[i]=start+i-1;
        }
        
        for(int i=0 ; i<m ; i++)
        {
            int find = input[i];
            printf("%d ",pos[find]-start);
            if(pos[find]==start)
            {
                continue;
            }
            
            for(int j=pos[find] ; j<end-1 ; j++)
            {
                data[j] = data[j+1];
                pos[data[j]] = j;
            }
            pos[find]=start-1;
            data[start--]=find;
        }
        printf("\n");
        
//        vector<int> data;
//        for(int i=n ; i>=1 ; i--)
//        {
//            data.push_back(i);
//            top[i]=i-1;
//        }
//
//        for(int i=0 ; i<m ; i++)
//        {
//            int find=input[i];
//            for(int j=n-top[find]-1; j>=0 ; j--)
//            {
//                if(find == data[j])
//                {
//                    int t= data[j];
//                    data.erase(data.begin()+j);
//                    data.push_back(t);
//                    top[find]=0;
//                    printf("%d ",n-j-1);
//                    break;
//                }
//                top[data[j]]=n-j-1;
//            }
//        }
    }
}
