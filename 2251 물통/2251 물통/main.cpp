//
//  main.cpp
//  2251 물통
//
//  Created by 김유진 on 2020/11/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[210][210][210];
bool resultCheck[210];
vector<int> result;
int A,B,C;

void func(int a, int b, int c);

void pour(int& give, int& take, int takeMax)
{
    take += give;
    give = 0;
    if(take>takeMax)
    {
        give = take-takeMax;
        take = takeMax;
    }
}

void next(int a, int b, int c, int num)
{
    switch (num) {
        case 0:
            pour(a,b,B);
            break;
        case 1:
            pour(a,c,C);
            break;
        case 2:
            pour(b,a,A);
            break;
        case 3:
            pour(b,c,C);
            break;
        case 4:
            pour(c,a,A);
            break;
        case 5:
            pour(c,b,B);
            break;
    }
    if(!check[a][b][c])
    {
//        printf("%d %d %d\n",a,b,c);
        check[a][b][c]=true;
        if(a==0 && !resultCheck[c])
        {
            resultCheck[c]=true;
            result.push_back(c);
        }
        func(a,b,c);
    }
}

void func(int a, int b, int c)
{
    for(int i=0 ; i<6 ; i++)
    {
        next(a, b, c, i);
    }
}

int main() {
    
    cin>>A>>B>>C;
    
    func(0,0,C);

    sort(result.begin(), result.end());
    for(int i=0 ; i<result.size() ; i++)
    {
        printf("%d ",result[i]);
    }
}
