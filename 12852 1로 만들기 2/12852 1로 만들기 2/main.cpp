//
//  main.cpp
//  12852 1로 만들기 2
//
//  Created by 김유진 on 08/01/2020.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

struct Data{
    int value;
    int index;
    int count;
};

int main()
{
    int n;
    int check[101000]={0,};
    scanf("%d",&n);
    
    vector<Data> data;
    
    check[n]=1;
    Data d = {n, -1, 0};
    data.push_back(d);
    
    int i=0;
    do{
        Data d = data[i];
        int v = d.value;
        int c = d.count;
        
        if(1 == v)
        {
            printf("%d\n",c);
            int idx = data[i].index;
            int num=0;
            int arr[1001000]={0,};
            
//            for(int a=0 ; a<=i ; a++)
//            {
//                printf("%d ",data[a].value);
//            }
            
            while(idx != -1)
            {
                arr[num++] = data[idx].value;
                idx = data[idx].index;
            }
            
            for(int i=num-1 ; i>=0 ; i--)
            {
                printf("%d ",arr[i]);
            }
            printf("1");
            
            return 0;
        }
        
        
        if(v%3==0 && check[v/3]==0)
        {
            check[v/3]=1;
            Data d = {v/3, i,c+1};
            data.push_back(d);
        }
        
        if(v%2==0 && check[v/2]==0)
        {
            check[v/2]=1;
            Data d = {v/2, i,c+1};
            data.push_back(d);
        }
        
        if(check[v-1]==0)
        {
            check[v-1]=1;
            Data d = {v-1, i,c+1};
            data.push_back(d);
        }
        
        i++;
    }while(true);
}
