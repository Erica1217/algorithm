/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <math.h>
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
    int A[220000]={0,};
    int B[220000]={0,};
    
    int left[220000]={0,};
    int right[220000]={0,};
    int s[220000]={0,};
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        int n;
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)
        {
            cin>>A[i];
        }
        for(int i=0 ; i<n ; i++)
        {
            cin>>B[i];
        }
        sort(A,A+n);
        sort(B,B+n);
        long long sum=0;
        int sMax=0;
        for(int i=0 ; i<n ; i++)
        {
            s[i] = abs(A[i]-B[i]);
            sMax = s[i] > sMax ? s[i]:sMax;
            sum+=s[i];
            if(i-1>=0)
                left[i] = s[i] - abs(A[i] - B[i-1]);
            if(i+1<n)
                right[i] = s[i] - abs(A[i] - B[i+1]);
        }
        
        
        if(sum==0 || n==1)
        {
            cout << "Case #" << test_case+1 << endl;
            cout << 0 << endl;
            continue;
        }
        int data[220000]={0,};
        int data2[220000]={0,};
        for(int i=1 ; i<n ; i++)
        {
            int t= data[i-1]+left[i];
            if(left[i]+s[i-1]< t)
            {
                data[i] = t;
            }
            else
            {
                data[i]=left[i]+s[i-1];
            }
        }
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            int t = data2[i+1] + right[i];
            if(right[i] + s[i+1] < t)
            {
                data2[i]=t;
            }
            else
            {
                data2[i] = right[i]+s[i+1];
            }
        }
        int m = data2[0] < data[n-1] ? data[n-1] : data2[0];
//        printf("%d\n",m);
        m = sMax < m ? m:sMax;
//        printf("%d %d\n",sum,m);
        Answer = sum-m;
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
