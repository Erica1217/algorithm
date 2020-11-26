//
//  main.cpp
//  3665 최종 순위
//
//  Created by 김유진 on 2020/05/16.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int in[1010]={0,};
        int out[1010]={0,};
        int n,m;
        int data[1010]={0,};
        int before=0;
        
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&data[i]);
            in[data[i]]=before;
            before=data[i];
        }
        int last = before;
        for(int i=n-2 ; i>=0 ; i--)
        {
            out[data[i]]=before;
            before = data[i];
        }
        
        scanf("%d",&m);
        vector<pair<int,int>> change;
        int a,b;
        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d",&a,&b);
            change.push_back(make_pair(a,b));
        }
        bool isPossible=true;
        int check[26000]={0,};
        while(m--)
        {
            int first=-1,second=-1;
            for(int i=0 ; i<change.size() ; i++)
            {
                int a=change[i].first;
                int b=change[i].second;
                
                if(in[a]==b && check[i]==0)
                {
                    first = b;
                    second = a;
                    check[i]=1;
                    break;
                }
                else if(in[b]==a && check[i]==0)
                {
                    first = a;
                    second = b;
                    check[i]=1;
                    break;
                }
            }
//            printf("%d %d\n",first,second);
            if(first==-1 && second==-1)
            {
                isPossible=false;
                printf("IMPOSSIBLE\n");
                break;
            }
            
            if(last==first)
            {
                last  = second;
            }
            else if(last == second)
            {
                last=first;
            }
            out[in[first]] = second;
            in[out[second]] = first;
            
            in[second] = in[first];
            in[first] = second;
            
            out[first] = out[second];
            out[second] = first;
            
        }
        
        if(isPossible)
        {
            int startIndex=-1;
//            for(int i=1 ; i<=n ; i++)
//            {
//                printf("%d %d %d\n",i,in[i],out[i]);
//            }
            
            for(int i=1 ; i<=n ; i++)
            {
                if(in[i]==0)
                {
                    startIndex=i;
                    break;
                }
            }
            while(startIndex!=0)
            {
                printf("%d ",startIndex);
                startIndex = out[startIndex];
            }
            printf("\n");
        }
    }
}
