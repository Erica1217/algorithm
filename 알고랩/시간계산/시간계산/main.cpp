//
//  main.cpp
//  시간계산
//
//  Created by 김유진 on 2020/03/30.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int a=0 ;a<t; a++)
    {
        int n;
        cin>>n;
        
        int s1,s2,s3;
        int e1,e2,e3;
        
        int r0=0,r1=0,r2=0,r3=0;
        for(int i=0 ; i<n ; i++)
        {
            cin>>s1>>s2>>s3;
            cin>>e1>>e2>>e3;
            
            r3 += e3 - s3;
            r2 += e2 - s2;
            r1 += e1 - s1;
        }
        
        if(r3<0)
        {
            int tmp = r3*(-1)/60 + (r3*(-1)%60==0 ? 0:1);
            r3+=tmp*60;
            r2-=tmp;
        }
        
        if(r2<0)
        {
            int tmp = r2*(-1)/60 + (r2*(-1)%60==0 ? 0:1);
            r2+=tmp*60;
            r1-=tmp;
        }
        
        r2+=r3/60;
        r3%=60;

        r1+=r2/60;
        r2%=60;
        
        r0+=r1/24;
        r1%=24;
        
        cout<<r0<<" "<<r1<<" "<<r2<<" "<<r3<<endl;
    }
}
