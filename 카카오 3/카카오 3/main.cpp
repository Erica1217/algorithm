#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> d[3][3][3][3][2000];
map<string ,int> m;


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    m["java"]=0;
    m["cpp"]=1;
    m["python"]=2;
    
    m["backend"]=0;
    m["frontend"]=1;
    
    m["junior"]=0;
    m["senior"]=1;
    
    m["pizza"]=0;
    m["chicken"]=1;
    
    for(int i=0 ; i<info.size() ; i++)
    {
        istringstream ss(info[i]);
        string s;
        int idx[5]={0,};
        int j=0;
        while (getline(ss, s, ' '))
        {
            idx[j] = m.find(s)->second;
            j++;
        }
        d[idx[0]][idx[1]][idx[2]][idx[3]][stoi(s)/1000].push_back(stoi(s));
    }
    
    for(int i=0 ; i<query.size() ; i++)
    {
        int find[10][5]={0,};
        int result = 0;
        
        istringstream ss(query[i]);
        string s;
        int j=0;
        while (getline(ss, s, ' '))
        {
            if(s=="and")
                continue;
            
            if(s=="-")
            {
                find[j][0]=0;
                find[j][1]= j==0 ? 2:1;
            }
            else
            {
                int t = m.find(s)->second;
                find[j][0]=t;
                find[j][1]=t;
            }
            j++;
        }
        
        int score = stoi(s);
        for(int a0=find[0][0] ; a0<=find[0][1] ; a0++){
            for(int a1=find[1][0] ; a1<=find[1][1] ; a1++){
                for(int a2=find[2][0] ; a2<=find[2][1] ; a2++){
                    for(int a3=find[3][0] ; a3<=find[3][1] ; a3++){
                        for(int a4=0 ; a4<(score/1000) ; a4++)
                        {
                            result+=d[a0][a1][a2][a3][a4].size();
                        }
                        int a4 =score/1000;
                        int mm = d[a0][a1][a2][a3][a4].size();
                        sort(d[a0][a1][a2][a3][a4].begin(),
                             d[a0][a1][a2][a3][a4].end());
                        for(int a5=mm-1 ; a5>=0 ; a5--)
                        {
                            if(score <= d[a0][a1][a2][a3][a4][a5])
                            {
                                result++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        
                    }
                }
            }
        }
        answer.push_back(result);
    }
    return answer;
}
