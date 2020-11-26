//
//  main.cpp
//  SCPC 1 다이어트
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
#include <algorithm>

using namespace std;

long long Answer;
 
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

        Answer = 0;
        
        int n,k;
        int a[220000]={0,};
        int b[220000]={0,};
        scanf("%d %d",&n,&k);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&a[i]);
        }
        
        for(int i=0; i<n ; i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        long long max=-1;
        for(int i=0 ; i<k ; i++)
        {
            int sum = a[i] + b[k-i-1];
            if(max==-1 || max<sum)
            {
                max=sum;
            }
        }
        
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << max << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
