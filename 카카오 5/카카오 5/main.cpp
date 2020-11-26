#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct sec{ //section
    int num;
    int time;
    bool isEnd;
};

bool cmp(sec a, sec b)
{
    if(a.time < b.time)
        return true;
    if(
    return false;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    priority_queue<int, vector<int> > q;
    int n = logs.size();
    
    vector<sec> data;
    
    for(int i=0 ; i<n ; i++)
    {
        int start = 0;
        int end=0;
        int h,m,s;
        
        if (sscanf(logs[i].substr(0,8).c_str(), "%d:%d:%d", &h, &m, &s) >= 2)
        {
           start = h *3600 + m*60 + s;
        }
        if (sscanf(logs[i].substr(9,8).c_str(), "%d:%d:%d", &h, &m, &s) >= 2)
        {
           end = h *3600 + m*60 + s;
        }
        
        sec section;
        section.num = i;
        section.time = start;
        section.isEnd=false;
        data.push_back(section);
        
        section.num = i;
        section.time = end;
        section.isEnd=true;
        data.push_back(section);
    }
    
    sort(data, data);
    for(int i=0 ; i<n*2 ; i++)
    {
        
    }
    

    return answer;
}
