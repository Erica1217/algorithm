#include <cstdio>
using namespace std;

int n;
int input1[600000];
int input2[600000];
int data[1100000];

int main()
{
    
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input1[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&input2[i]);
        data[input2[i]]=i;
    }
    
    int check[600000]={0,};
    int max=-1;
    int result=0;
    for(int i=0 ; i<n ; i++)
    {
        int pos = data[input1[i]];
        check[pos]=1;
        if(max < pos)
        {
            max=pos;
        }
        else
        {
            for(int j=pos+1 ; j<=max ; j++)
            {
                if(check[j]==1)
                {
                    result+=1;
                }
            }
        }
    }
    printf("%d",result);
}
