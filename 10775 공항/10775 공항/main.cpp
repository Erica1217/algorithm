//
//  main.cpp
//  10775 공항
//
//  Created by 김유진 on 2020/04/17.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <deque>
using namespace std;

int main()
{
    int g,p;
    int data[11000]={0,};
    scanf("%d %d",&g,&p);
    
    deque<int> deq1;
    deque<int> deq2;
    for(int i=0 ; i<p ; i++)
    {
        scanf("%d",&data[i]);
    }
    
    for(int i=0 ; i<p ; i++)
    {
        while(!deq1.empty() && data[i]<deq1.back())
        {
//            printf("~%d %d [%d]\n",data[i],deq1.back(),deq1.size());
            deq2.push_back(deq1.back());
            deq1.pop_back();
            if(deq2.size()+deq1.size()>deq2.back())
            {
                printf("%d\n",i);
                return 0;
            }
        }
        
      while(!deq2.empty() && data[i]>=deq2.back())
      {
//          printf("!%d %d [%d]\n",data[i],deq2.back(),deq2.size());
          deq1.push_back(deq2.back());
          deq2.pop_back();
          if(deq1.size()>deq1.back())
          {
              printf("%d\n",i);
              return 0;
          }
      }
        
        deq1.push_back(data[i]);
//        printf("@%d %d\n",deq1.size(), deq1.back());
        if(deq1.size() > deq1.back())
        {
            printf("*%d\n",i);
            return 0;
        }
    }
    printf("%d\n",p);
}
