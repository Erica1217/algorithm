//
//  main.cpp
//  1790 수 이어쓰기 2
//
//  Created by 김유진 on 2020/07/20.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <string>
using namespace std;
int main()
{
    long long n,k;
    scanf("%lld %lld",&n,&k);
    
    long long num=0;
    long long cur=0;
    for(long long i=1, t=9 ;  ; i++, t*=10)
    {
        if(num+(i*t)>=k)
        {
            k-=num;
            if(k==0)
            {
                printf("%d", cur<=n ? 9 :-1);
                return 0;
            }
            cur+=(k/i);
            k=k%i;
            if(k==0)
            {
                printf("%d\n",cur<=n ? cur%10 :-1);
                return 0;
            }
            
            cur++;
//            printf("%d\n",cur);
            string s = to_string(cur);
            if(cur>n)
            {
                printf("-1");
                return 0;
            }
            printf("%c\n",s.at(k-1));
            return 0;
        }
        cur+=t;
        num+=(i*t);
//        printf("%lld %lld %lld\n",i,num,t);
    }
}
