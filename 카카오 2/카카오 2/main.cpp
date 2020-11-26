#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int a=0 ; a<course.size() ; a++)
    {
        int n = course[a];
        map<string, int> m;
        int maxValue=2;
        for(int i=0 ; i<orders.size() ; i++)
        {
            if(orders[i].size() < n)
                continue;
            
            sort(orders[i].begin(), orders[i].end());
            
            // string -> vector
            vector<int> v;
            for(int j=0 ; j<orders[i].size()-n ; j++)
            {
                v.push_back(0);
            }
            for(int j=0 ; j<n ; j++)
            {
                v.push_back(1);
            }
            sort(v.begin(), v.end());
            
            // 조합으로 다 map에 추가
            do{
                
                string s="";
                for(int j=0 ; j<orders[i].size() ; j++)
                {
                    if(v[j]==1)
                    {
                        s+=orders[i][j];
                    }
                }
                cout<<s<<endl;
                
                if(m.find(s)== m.end())
                {
                    m[s]=1;
                }
                else
                {
                    m[s] = m.find(s)->second+1;
                }
                
                
                if(m[s]>maxValue)
                {
                    maxValue = m[s];
                }
                
            }while(next_permutation(v.begin(), v.end()));
        }
        for(auto i=m.begin() ; i!=m.end() ; i++)
        {
            if(maxValue == i->second)
                answer.push_back(i->first);
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}
