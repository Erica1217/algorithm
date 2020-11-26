//
//  main.cpp
//  9465 스티커
//
//  Created by 김유진 on 22/09/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int T;
    
    cin >> T;
    for(int i=0 ; i<T ; i++)
    {
        int n;
        int input[110000][5]={0,};
        int data[110000][5]={0,};
        cin>>n;
        for(int j=0 ; j<2 ; j++)
        {
            for(int k=1 ; k<=n ; k++)
            {
                cin>>input[k][j];
            }
        }

        data[0][0]=0;
        data[0][1]=0;
        data[1][0]=input[1][0];
        data[1][1]=input[1][1];

        for(int j=2 ; j<=n ; j++)
        {
            for(int k=0 ; k<2 ; k++)
            {
                int score = input[j][k];
                int max =data[j-1][k];
                if( data[j-1][1-k]+score > max)
                {
                    max = data[j-1][1-k]+score;
                }
                else if(data[j-2][k]+score>max){
                   max=data[j-2][k]+score;
                }
                else if(data[j-2][1-k]+score>max){
                    max=data[j-2][1-k]+score;
                }
                data[j][k]=max;
            }
        }
        
        int max=data[n][0];
        if(max<data[n][1])
        {
            max=data[n][1];
        }
        cout<<max<<endl;
    }
}
