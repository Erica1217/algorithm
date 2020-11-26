//
//  main.cpp
//  SCPC 2 카드게임
//
//  Created by 김유진 on 2020/08/21.
//  Copyright © 2020 김유진. All rights reserved.
//

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int Answer;
int check[3300][3300]={0,};
int main(int argc, char** argv)
{
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {

        int n,k;
        int a[3300]={0,};
        int b[3300]={0,};
        scanf("%d %d",&n,&k);
        Answer = 0;

        memset(check,0,sizeof(check));
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&b[i]);
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                printf("%d ",check[i][j]);
            }
            printf("\n");
        }
        
        
        check[0][0]=1;
        int an=1, bn=0;
        queue<pair<int ,int> > q;
        q.push(make_pair(0,0));
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            printf("*%d %d\n",x,y);
            q.pop();
            
            int sum=0;
            for(int i=x; i<n ; i++)
            {
                sum+=a[i];
                if(sum>k)
                    break;
                if(check[i+1][y]==0)
                {
                    check[i+1][y]=check[x][y]*-1;
                    q.push(make_pair(i+1,y));
                    if(check[i+1][y]==1)
                    {
                        an++;
                    }
                    else
                    {
                        bn++;
                    }
                }
            }
            sum=0;
            for(int i=y ; i<n ; i++)
            {
                sum+=b[i];
                if(sum>k)
                    break;
                if(check[x][i+1]==0)
                {
                    check[x][i+1]=check[x][y]*-1;
                    q.push(make_pair(x, i+1));
                    if(check[x][i+1]==1)
                    {
                        an++;
                    }
                    else
                    {
                        bn++;
                    }
                }
            }
        }
        
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout<<an<<" "<<bn<<endl;
//        cout << result << " "<< (n+1)*(n+1)-result<<  endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
