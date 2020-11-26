//
//  main.cpp
//  9019 DSLR
//
//  Created by 김유진 on 16/08/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

struct Data{
    int arr, num, idx;
    char value;
    
    Data(){};
    Data(int _arr,int _num,int _idx,char _value):arr(_arr),num(_num),idx(_idx),value(_value){};
};

int main()
{
    int n;
    scanf("%d",&n);
    vector<Data> v;
    for(int i=0 ; i<n; i++)
    {
        int A,B;
        bool check[10010]={0,};
        int start=0;
        scanf("%d %d",&A,&B);
        
        v.clear();
        check[A]=true;
        Data init;
        init.arr=A;
        init.idx=0;
        init.value=0;
        init.num=0;
        v.push_back(init);
        
        do{
            Data d = v.at(start);
            int a = d.arr;
            int N = d.num;
            int index = d.idx;
            
            if(a==B)
            {
                char dap[10010]={0,};
                dap[N-1]=d.value;
                for(int i=N-2 ; i>=0 ; i--)
                {
                    dap[i]=v.at(index).value;
                    index=v.at(index).idx;
                }
                printf("%s\n",dap);
                break;
            }
            
            int D=(a*2)%10000;
            if(!check[D])
            {
                check[D]=true;
                Data data;
                v.push_back(Data(D,N+1,start,'D'));
            }
            int S=(10000+(a-1))%10000;
            if(S>=0 && !check[S])
            {
                check[S]=true;
                v.push_back(Data(S,N+1,start,'S'));
            }
            
            int t1=a/1000;
            int t2 = (a%1000)*10+t1;
            if(!check[t2])
            {
                check[t2]=true;
                v.push_back(Data(t2,N+1,start,'L'));
            }
            
            t1=a%10;
            t2=(a/10)+(1000*t1);
            if(!check[t2])
            {
                check[t2]=true;
                v.push_back(Data(t2,N+1,start,'R'));
            }
            start++;
        }while(start!=v.size());
    }
}
