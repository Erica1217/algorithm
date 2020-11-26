//
//  main.cpp
//  14746 Closest Pair
//
//  Created by 김유진 on 20/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int pn,qn;
    int c1,c2;
    int P[510000]={0,};
    int Q[510000]={0,};
    cin>>pn>>qn;
    cin>>c1>>c2;
    for(int i=0; i<pn ; i++)
    {
        cin>>P[i];
    }
    for(int i=0; i<qn ; i++)
    {
        cin>>Q[i];
    }
    
    sort(P,P+pn);
    sort(Q,Q+qn);
    
    if(P[pn-1] < Q[0])
    {
        int distance = abs(c1-c2)+abs(Q[0]-P[pn-1]);
        cout<<distance<<" 1";
        return 0;
    }
    
    if(Q[qn-1]<P[0])
    {
        int distance = abs(c1-c2)+abs(Q[qn-1]-P[0]);
        cout<<distance<<" 1";
        return 0;
    }
    

    int i=0,j=1;
//    long long min=9999876543210;
    long long min = abs(P[0] - Q[0]);
    int result=1;
    while(i!=pn && j!=qn)
    {
//        printf("%d %d %d\n", Q[j-1], P[i], Q[j]);
        if(Q[j-1]<=P[i] && Q[j] >= P[i] )
        {
//            printf("*%d %d %d\n", Q[j-1], P[i], Q[j]);
            if(min>abs(P[i]-Q[j]))
            {
                min=abs(P[i]-Q[j]);
                result=1;
            }
            else if(min==abs(P[i]-Q[j]))
            {
                result++;
            }
            
            if(min>abs(Q[j-1]-P[i]))
            {
                min=abs(Q[j-1]-P[i]);
                result=1;
            }
            else if(min==abs(Q[j-1]-P[i]))
            {
                result++;
            }
            i++;
        }
        else if(Q[j-1]>=P[i] && Q[j] >= P[i])
        {
            i++;
        }else
        {
            j++;
        }
    }
    
    if(i==j && min>abs(P[pn-1]-Q[qn-1]))
    {
        min=abs(P[pn-1]-Q[qn-1]);
        result=1;
    }
    else if(min==abs(P[pn-1]-Q[qn-1]))
    {
        result++;
    }
    
    
    long long distance = abs(c1-c2)+abs(min);
    cout<<distance<<" "<<result;
}
