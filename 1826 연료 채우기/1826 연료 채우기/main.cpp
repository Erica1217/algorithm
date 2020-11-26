//
//  main.cpp
//  1826 연료 채우기
//
//  Created by 김유진 on 2020/06/06.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;
typedef pair<int ,int> gas;

int result[1100000]={0,};
int fuel_amount[1100000]={0,};

struct sortf{
    bool operator() (gas a, gas b){
        if(a.first < b.first){
            return 0;
        }
        return 1;
    }
};

int main()
{
    int n;
    priority_queue<gas, vector<gas>, sortf> q; // input 저장
    scanf("%d",&n);
    int a,b;
    int end,fuel;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d", &a,&b);
        q.push(make_pair(a,b));
    }
    scanf("%d %d",&end,&fuel);
    
    
    //first : 어디까지 갈 수 있는지, second : 주유소 몇 번 들렀는지
    priority_queue<gas, vector<gas>, sortf> data; //실제 답
    data.push(make_pair(fuel,0));
    int result[11000]={0,};
    result[0] = fuel;
    int start= 0;
    int max=0;
    for(int i=0 ; i<n ; i++)
    {
        int pos = q.top().first;
        int amount = q.top().second;
        q.pop();
        
        for(int j=max ; j>=start ; j--)
        {
            if(result[j] >= pos)
            {
                if(result[j+1] < amount+result[j])
                {
//                    printf("[%d %d] %d %d\n",i,j+1,result[j+1], amount+result[j]);
                    result[j+1] = amount+result[j];
                    max = j+1<max? max:j+1;
                }
            }
            else
            {
                start=j;
                break;
            }
        }
    }
    for(int i=0 ; i<=max ; i++)
    {
        if(end<=result[i])
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
}
