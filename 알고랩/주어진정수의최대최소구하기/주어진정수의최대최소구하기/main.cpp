//
//  main.cpp
//  주어진정수의최대최소구하기
//
//  Created by 김유진 on 2020/03/24.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int T;
    cin>>T;
    for(int i=0 ; i<T ; i++)
    {
        int n;
        cin>>n;
        int data[110];
        for(int j=0 ; j<n ; j++)
        {
            cin>>data[j];
        }
        
        int max=data[0],min=data[0];
        for(int j=0 ; j< n ;j++)
        {
            max = data[j]>max ? data[j]:max;
            min = data[j]<min ? data[j]:min;
        }
        cout<<max<<" "<<min<<"\n";
    }
    return 0;
}
