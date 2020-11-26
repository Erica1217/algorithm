/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data;
int Answer;
int n,k,q;
int t[220000]={0,};

void init()
{
    for(int i=n-1 ;i>=1 ; i--)
    {
        t[i] = t[i<<1] + t[i<<1 | 1];
    }
}

void update(int pos)
{
    if(pos==0)
    {
        return;
    }
    pos/=2;
    t[pos] = t[pos<<1] + t[pos<<1 | 1];
    update(pos);
}

int query(int l, int r)
{
    int ret=0;
    for(l=l+n, r=r+n ; l<r ; l>>=1, r>>=1)
    {
        if(l&1) ret+=t[l++];
        if(r&1) ret+=t[--r];
    }
    return ret;
}

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
        data.clear();
        int input[220000]={0,};
        cin>>n>>k>>q;
        for(int i=0; i<n ; i++)
        {
            cin>>input[i];
            t[n+i]=input[i];
        }
        init();
        
        cout << "Case #" << test_case+1 << endl;
        for(int j=0 ; j<=n-k ; j++)
        {
            data.push_back(query(j,j+k));
        }
        vector<int> tmp;
        tmp.assign(data.begin(), data.end());
        sort(tmp.begin(), tmp.end());
        cout<<tmp[tmp.size()/2]<<"\n";
        int a,b;
        for(int i=0 ; i<q ; i++)
        {
            cin>>a>>b;
            t[n+a-1]=b;
            update(n+a-1);
            int start = a-k<0 ? 0 : a-k;
            int end = a+k>n-k? n-k : a+k;
            for(int j=start ; j<=end ; j++)
            {
                data[j] = query(j,j+k);
            }
            vector<int> tmp;
            tmp.assign(data.begin(), data.end());
            sort(tmp.begin(), tmp.end());
            cout<<tmp[tmp.size()/2]<<"\n";
        }
        Answer = 0;
    }

    return 0;//Your program should return 0 on normal termination.
}
